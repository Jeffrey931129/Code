#ifndef _FUNC_H
#define _FUNC_H
#include <iostream>
#include <string>

class Codec {
public:
    Codec(std::string s): encoded{false}, code_str{s} { }
    virtual ~Codec() { } // virtual destructor; do nothing
    virtual void encode() = 0;
    virtual void decode() = 0;
    void show(std::ostream& os) const {
        os << code_str;
    }
    bool is_encoded() const { return encoded; }
protected:
    bool encoded;
    std::string code_str;
};

Codec* getCodec(const std::string& type, const std::string& is);

#endif
