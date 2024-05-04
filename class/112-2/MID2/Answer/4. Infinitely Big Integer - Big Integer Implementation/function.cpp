#include "function.h"

// Darray
Darray::~Darray() {
    delete []this->data;
}

void Darray::pushback(int x) {
    if (size >= capacity)
        resize();
    this->data[size++] = x;
}

void Darray::popback() {
    if (size > 0)
        size--;
}

void Darray::resize() {
    int *tmp = new int[capacity << 1];
    for (int i = 0; i < capacity; i++)
        tmp[i] = this->data[i];
    delete []this->data;
    this->data = tmp;
    capacity <<= 1;
}

int& Darray::operator[] (int x) {
    return this->data[x];
}

void Darray::clear() {
    this->size = 0;
}

int Darray::length() {
    return this->size;
}

// INT
std::istream &operator>>(std::istream &a, INT &x) {
    x.data.clear();
    std::string s;
    a >> s;
    int blen = s.length();
    for (int i = 0; i < blen; i++) {
        x.data.pushback(s.at(blen - i - 1) - '0');
    }
    return a;
}
std::ostream &operator<<(std::ostream &a, INT &x) {
    int len = x.data.length();
    for (int i = len - 1; i >= 0; i--) {
        a << (char)(x.data[i] + '0');
    }
    return a;
}
int max(int a, int b) {
    return a > b ? a : b;
}
void INT::operator+= (INT &b) {
    int lena = this->data.length();
    int lenb = b.data.length();
    int len = max(lena, lenb);
    if (lena < lenb) {
        for (int i = lenb - lena; i > 0; i--)
            this->data.pushback(0);
    }
    for (int i = 0; i < len; i++) {
        if (i < lenb)
            this->data[i] += b.data[i];
    }
    for (int i = 0; i < len - 1; i++) {
        this->data[i + 1] += this->data[i] / 10;
        this->data[i] %= 10;
    }
    if (this->data[len - 1] > 9) {
        this->data.pushback(1);
        this->data[len - 1] -= 10;
    }
}

