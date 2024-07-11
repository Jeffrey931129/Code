#include <iostream>
#include <string>
//#include "function.h"
using namespace std;

class Codec {
public:
    Codec(string s): encoded{false}, code_str{s} { }
    virtual ~Codec() { } // virtual destructor; do nothing
    virtual void encode() = 0;
    virtual void decode() = 0;
    void show(ostream& os) const {
        os << code_str;
    }
    bool is_encoded() const { return encoded; }
protected:
    bool encoded;
    string code_str;
};

Codec* getCodec(const string& type, const string& is);

ostream& operator<<(ostream& os, Codec& data)
{
    data.show(os);
    return os;
}

void encode_decode(Codec & data)
{
    if (!data.is_encoded())
        data.encode();
    else
        data.decode();
}


int main()
{
    string input_string;
    cin >> input_string;

    Codec** CodecPtr = new Codec*[2];

    CodecPtr[0] = getCodec("Dummy",input_string);
    encode_decode(*CodecPtr[0]);
    cout << "Dummy encoding: ";
    cout << *CodecPtr[0] << endl;
    encode_decode(*CodecPtr[0]);
    cout << "Dummy decoding: ";
    cout << *CodecPtr[0] << endl;

    CodecPtr[1] = getCodec("RLE",input_string);
    encode_decode(*CodecPtr[1]);
    cout << "RLE encoding: ";
    cout << *CodecPtr[1] << endl;
    encode_decode(*CodecPtr[1]);
    cout << "RLE decoding: ";
    cout << *CodecPtr[1] << endl;

    delete CodecPtr[0];
    delete CodecPtr[1];
    delete [] CodecPtr;
}

class Dummy:public Codec{
public:
    Dummy(string s):Codec(s){}
    void encode() override{
        encoded=1;
    }
    void decode() override{
        encoded=0;
    }
};
class RLE:public Codec{
public:
    RLE(string s):Codec(s){}
    void encode() override{
        int size=code_str.size(),rec=1;
        char pre=code_str[size-1];
        for(int i=size-2;i>=0;i--){
            if(code_str[i]==pre){
                rec++;
            }
            else{
                if(rec>2){
                    code_str.replace(i+1,rec-1,to_string(rec));
                }
                rec=1;
            }
            pre=code_str[i];
        }
        if(rec>2){
            code_str.replace(0,rec-1,to_string(rec));
        }
        encoded=1;
    }
    void decode() override{
        int size=code_str.size(),num=0,era_num=0;
        for(int i=0;i<size;i++){
            if(code_str[i]<='9'){
                num=num*10+code_str[i]-'0';
                era_num++;
            }
            else{
                if(num>0){
                    code_str.erase(i-era_num,era_num);
                    i-=era_num;
                    for(int j=0;j<num-1;j++){
                        code_str.insert(i,1,code_str[i]);
                        i++;
                    }
                    size=code_str.size();
                }
                num=0,era_num=0;
            }
        }
        encoded=0;
    }
};
Codec* getCodec(const string& type, const string& is){
    if(type=="Dummy"){
        return new Dummy(is);
    }
    else{
        return new RLE(is);
    }
}