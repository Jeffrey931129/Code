#include "function.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& is, Fraction& frac) {
    char delim;
    is >> frac.numerator >> delim >> frac.denominator;
    return is;
}

Fraction Fraction::operator+(const Fraction& frac) {
    long long commonDenominator = denominator * frac.denominator;
    long long num1 = numerator * frac.denominator;
    long long num2 = frac.numerator * denominator;
    long long sumNumerator = num1 + num2;
    return Fraction(sumNumerator, commonDenominator);
}

bool Fraction::operator<(const Fraction& frac) {
    return numerator * frac.denominator < frac.numerator * denominator;
}

bool Fraction::operator>(const Fraction& frac) {
    return numerator * frac.denominator > frac.numerator * denominator;
}

bool Fraction::operator<=(const Fraction& frac) {
    return !(*this > frac);
}

bool Fraction::operator>=(const Fraction& frac) {
    return !(*this < frac);
}

FractionList::FractionList(const FractionList& frac) {
    if (frac.fraction) fraction = new Fraction(*(frac.fraction));
    else fraction = nullptr;
    if (frac.nextFraction) nextFraction = new FractionList(*(frac.nextFraction));
    else nextFraction = nullptr;
}

FractionList& FractionList::operator=(const FractionList& frac) {
    if (this != &frac) {
        if (frac.fraction) {
            delete fraction;
            fraction = new Fraction(*(frac.fraction));
        }
        if (frac.nextFraction) {
            delete nextFraction;
            nextFraction = new FractionList(*(frac.nextFraction));
        }
    }
    return *this;
}

FractionList& FractionList::operator+=(const Fraction& frac) {
    FractionList *list = this;
    while (list->nextFraction) list = list->nextFraction;
    list->nextFraction = new FractionList(new Fraction(frac));
    return *this;
}

Fraction FractionList::getResult() {
    Fraction result = Fraction(*fraction);
    if (!nextFraction) return Fraction(result);
    return Fraction(result + nextFraction->getResult());
}

FractionList::~FractionList() {
    delete fraction;
    if (nextFraction) delete nextFraction;
}
