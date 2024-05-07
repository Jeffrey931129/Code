#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cmath>
//#include "function.h"
using namespace std;

class Darray {
    public:
        Darray() {
            capacity = 100;
            size = 0;
            data = new int[capacity];
        };
        ~Darray();
        int& operator[](int);
        void pushback(int x);
        void popback(void);
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};

class INT {
    public:
        void operator+=(INT&);
        friend std::istream &operator>>(std::istream &, INT &);
        friend std::ostream &operator<<(std::ostream &, INT &);
    private:
        Darray data;
};

class randGen {
private:
    unsigned int z1, z2, z3, z4;
public:
    randGen(int seed) {
        z1 = seed;
        z2 = seed << 10;
        z3 = seed << 20;
        z4 = seed << 30;
    };
    int next(int x) {
        return next() % x;
    }
    void next(INT &b) {
        int len = next() & ((1 << 21) - 1);
        stringstream ss;
        ss << next(9) + 1;
        while (len--)
            ss << next(10);
        ss >> b;
    }
    unsigned int next() {
        unsigned int b;
        b  = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b  = ((z2 << 2) ^ z2) >> 27; 
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b  = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b  = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
};
const int mul = 9487;
const int mod = 99999989;
typedef long long ll;
class rollingHash {
    public:
    rollingHash() {
        hash = 0;
    }
    void push(INT &x) {
        stringstream ss;
        ss << x;
        string s;
        ss >> s;
        int tmp_hash = 0;
        for (int i = 0; i < s.length(); i++) {
            tmp_hash += s[i];
            tmp_hash += (tmp_hash << 10);
            tmp_hash ^= (tmp_hash >> 6);
        }
        tmp_hash += tmp_hash << 3;
        tmp_hash ^= tmp_hash >> 11;
        tmp_hash += tmp_hash << 15;
        push(tmp_hash);
    }
    void push(int x) {
        hash = (((hash * mul) % mod + x) % mod + mod) % mod;
    }
    ll getHash() {
        return hash;
    }
    private:
        ll hash;
};

inline void case1(randGen &rand, rollingHash &hash) {
    INT x, y;
    rand.next(x);
    //hash.push(x);
    rand.next(y);
    //hash.push(y);
    x += y;
    hash.push(x);
    hash.push(y);
}
inline void case2(randGen &rand, rollingHash &hash, int iter=5) {
    for (int i = 0; i < iter; i++) {
        case1(rand, hash);
    }
}
inline void case3(randGen &rand, rollingHash &hash, int iter=4) {
    INT x, y;
    for (int i = 0; i < iter; i++) {
        rand.next(x);
        hash.push(x);
        rand.next(y);
        hash.push(y);
        x += y;
        hash.push(x);
        hash.push(y);
    }
}
inline void case4(randGen &rand, rollingHash &hash) {
    case2(rand, hash, 2);
    case3(rand, hash, 2);
    INT x, y;
    rand.next(x);
    rand.next(y);
    //hash.push(x);
    //hash.push(y);
    for (int i = 0; i < 8; i++) {
        int action = rand.next(4);
        if (action == 0) {
            rand.next(x);
            hash.push(x);
        }else if (action == 1) {
            rand.next(y);
            hash.push(y);
        }else if (action == 2) {
            x += y;
            hash.push(x);
            //hash.push(y);
        }else {
            y += x;
            //hash.push(x);
            hash.push(y);
        }
    }
}

int main() {
    int seed, testcase;
    cin >> seed >> testcase;
    randGen rand(seed);
    rollingHash hash;
    INT x, y;
    switch(testcase) {
        case 1:
            case1(rand, hash);
            break;
        case 2:
            case2(rand, hash);
            break;
        case 3:
            case3(rand, hash);
            break;
        case 5:
            cin >> x;
            cin >> y;
            hash.push(x);
            hash.push(y);
            x += y;
            hash.push(x);
        case 4:
            case4(rand, hash);
            break;
    }
    cout << hash.getHash() << " AC" << endl;
    return 0;
}
// int main(){
//     INT a,b;
//     cin>>a>>b;
//     a+=b;
//     cout<<a<<endl<<b<<endl;
// }

Darray::~Darray(){
    delete[] data;
}
int& Darray::operator[](int i){
    return data[i];
}
void Darray::pushback(int x){
    if(size==capacity) resize();
    data[size++]=x;
}
void Darray::popback(void){
    if(size){
        data[--size]=0;
    }
}
void Darray::clear(void){
    for(int i=0;i<size;i++){
        data[i]=0;
    }
    size=0;
}
int Darray::length(void){
    return size;
}
void Darray::resize(void){
    capacity*=2;
    int* temp=new int[capacity];
    for(int i=0;i<size;i++){
        temp[i]=data[i];
    }
    delete[] data;
    data=temp;
}
void INT::operator+=(INT &x){
    int len1=data.length(),len2=x.data.length(),i=0;
    for(;len1<len2;len1++){
        data.pushback(0);
    }
    int carry=0;
    for(;i<len2;i++){
        data[i]+=x.data[i]+carry;
        if(data[i]>=10){
            data[i]-=10;
            carry=1;
        }
        else carry=0;
    }
    for(;i<len1;i++){
        data[i]+=carry;
        if(data[i]>=10){
            data[i]-=10;
            carry=1;
        }
        else carry=0;
    }
    if(carry) data.pushback(1);
}
istream &operator>>(istream &in, INT &x){
    x.data.clear();
    string s;
    in>>s;
    for(int i=s.size()-1;i>=0;i--) x.data.pushback(s[i]-'0');
    return in;
}
ostream &operator<<(ostream &out, INT &x){
    for(int i=x.data.length()-1;i>=0;i--) out<<x.data[i];
    return out;
}