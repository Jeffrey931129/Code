#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "function.h"

class DummyCodec: public Codec {
public:
    DummyCodec(std::string s): Codec{s} { }
    virtual ~DummyCodec() { } // virtual destructor; do nothing

    virtual void encode() override {
        encoded = true;
    }

    virtual void decode() override {
        encoded = false;
    }
};

class RleCodec: public Codec
{
public:
    RleCodec(std::string s): Codec{s} { }
    virtual ~RleCodec() { } // virtual destructor; do nothing

    virtual void encode() override;

    virtual void decode() override;
};

void RleCodec::encode()
{
	int cnt = 0;
	char prev = '\0';
	std::stringstream ss;

	code_str.push_back('$');
	for (auto c : code_str) {
		if (c!=prev) {
			if (cnt>0) {
				if (cnt==1)
					ss << prev;
				else if (cnt==2)
					ss << prev << prev;
				else
					ss << cnt << prev;
			}
			prev = c;
			cnt = 1;
		} else {
			++cnt;
		}
	}
	code_str = ss.str();
	encoded = true;
}

void RleCodec::decode()
{
	std::stringstream os;
	std::string int_str;
	for (auto c : code_str) {
		if (std::isdigit(c)) {
			int_str.push_back(c);
		} else {
			int cnt = 0;
			std::stringstream is{int_str};
			is >> cnt;
			if (cnt==0) {
				os << c;
			} else {
				for (int i=0; i<cnt; ++i)
					os << c;
			}
			int_str.clear();
		}
	}

	code_str = os.str();
	encoded = false;
}


Codec* getCodec(const std::string& type, const std::string& is)
{
    if (type == "Dummy") {
        return new DummyCodec{is};
    } else if (type == "RLE") {
        return new RleCodec{is};
    } else {
        return nullptr;
    }
}
