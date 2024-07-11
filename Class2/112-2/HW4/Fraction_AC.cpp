#include <iostream>
#include <string>
//#include "function.h"
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <math.h>

using namespace std;

class Fraction {
    private:
        long long numerator;    // 分子
        long long denominator;  // 分母

        // Parses and returns the numerator from a string representation of a fraction.
        static int parseNumerator(const string& frac) {
            size_t pos = frac.find('/');
            return stoi(frac.substr(0, pos));
        }

        // Parses and returns the denominator from a string representation of a fraction.
        static int parseDenominator(const string& frac) {
            size_t pos = frac.find('/');
            int den = stoi(frac.substr(pos + 1));
            return den;
        }

    public:
        // Default constructor for the Fraction class.
        Fraction() : numerator(0), denominator(1) {}

        // Constructor that initializes a fraction and reduces it using the greatest common divisor.
        Fraction(long long num, long long den) {
            long long gcd = __gcd(num, den);
            numerator = num / gcd;
            denominator = den / gcd;
        }

        // Constructor that creates a fraction from a string representation.
        // This is a "Delegating Constructor", 
        // it refers to a constructor in a class that calls another constructor from the same class.
        Fraction(string frac) : Fraction(parseNumerator(frac), parseDenominator(frac)) {}

        /* ***** TODO ***** */
        // Adds two fractions and returns the result as a new fraction object
        Fraction operator+(const Fraction& frac);

        /* ***** TODO ***** */
        // Multiplies this fraction by another fraction and modifying this object.
        Fraction& operator*=(const Fraction& frac);

        /* ***** TODO ***** */
        // Returns the integer part of the fraction by dividing the numerator by the denominator.
        //
        // Example.
        // --> Fraction f("9/4");             // 2.25
        //     cout << f.getIntegerPart();    // 2
        long long getIntegerPart();

        /* ***** TODO ***** */
        // Returns a specific digit of the decimal part of the fraction,
        // by repeatedly multiplying the remainder by 10.
        //
        // Example.
        // --> Fraction f("3/7");             // 0.428571...
        //     cout << f(1);                  // 4
        //     cout << f(2);                  // 2
        int operator()(const int& digit);

        /* ***** TODO ***** */
        // Stream insertion operator that outputs the fraction to an output stream 
        // in the form "numerator/denominator".
        //
        // Example.
        // --> Fraction f("2/3");
        //     cout << f;                     // 2/3
        friend ostream& operator<<(ostream& os, const Fraction& frac);

        /* ***** TODO ***** */
        // Stream extraction operator that inputs the fraction from an input stream 
        // in the form "numerator/denominator".
        //
        // Example.
        // --> Fraction f;
        //     cin >> f;                      // 6/7 (numerator = 6, denominator = 7)
        friend istream& operator>>(istream& is, Fraction& frac);

        void debug(){
            cout<<numerator<<"/"<<denominator<<" ";
        }
};

class FractionList {
    private:
        Fraction *fraction;
        FractionList *nextFraction;

    public:
        // Default constructor for the FractionList class.
        FractionList(): fraction(nullptr), nextFraction(nullptr) {}

        // Constructor that initializes the list with a single fraction.
        FractionList(Fraction *f): fraction(f), nextFraction(nullptr) {}

        /* ***** TODO ***** */
        // Copy constructor: performs a "deep copy" of the entire FractionList.
        // This is necessary to ensure that each FractionList instance
        // has its own separate copies of Fraction objects and linked FractionList nodes,
        // preventing issues related to multiple deletions of the same memory during destruction.
        FractionList(const FractionList& frac);

        /* ***** TODO ***** */
        // Assigns a new value to the FractionList object, replacing its current contents,
        // and properly disposing of the old contents.
        // Notice: Adding "return *this" allows the operator to return a reference to the object itself. 
        // It supports chaining multiple assignments together in a single statement (e.g. A = B = C), 
        // as each assignment operation can then be followed by another, 
        // using the result of the previous assignment.
        FractionList& operator=(const FractionList& frac);

        /* ***** TODO ***** */
        // Destructor that recursively deletes all fractions in the list to prevent memory leaks.
        ~FractionList();

        /* ***** TODO ***** */
        // Depending on the operation specified, 
        // either adds the given fraction to the list or multiplies the current fraction by it.
        // When the operator (ope) is "*", multiply the fractions directly; 
        // when "+", create a new fraction for each addition, linking them together using nextFraction.
        //
        // Hint.
        // --> Use the "*=" operator, which has been overloaded to multiply a fraction and assign the result, 
        //     to perform the multiplication on the last fraction in the list.
        FractionList* operation(string ope, Fraction *frac);

        /* ***** TODO ***** */
        // At the end of all * operations, 
        // traverse through the FractionList and summing them up to compute the final result.
        //
        // Hint.
        // --> Use the "+" operator, which has been overloaded to add fractions, 
        //     to perform the addition of the fractions in the list.
        Fraction getResult();

        void debug(){
            fraction->debug(); cout<<endl;
            if(nextFraction!=NULL) nextFraction->debug();
        }
};

int main() {
    Fraction fraction;
    while (cin >> fraction) {

        FractionList *toMultiply = new FractionList(new Fraction(fraction));
        FractionList *lastFraction = toMultiply;

        string ope;
        while (cin >> ope) {
            if (ope == "=") break;
            cin >> fraction;
            lastFraction = lastFraction->operation(ope, new Fraction(fraction));
            toMultiply->debug(); cout<<endl;
        }
        cin >> ope;
        cout<<"----------"<<endl;
        FractionList *multiplied = new FractionList(*toMultiply), toAdd;
        multiplied->debug();
        cout<<"----------"<<endl;
        Fraction answer = (toAdd = *multiplied).getResult();
        toAdd.debug();
        cout<<"----------"<<endl;
        delete toMultiply, multiplied;
        cout << answer << " ";
        cout << answer.getIntegerPart() << ".";
        for (int i = 1; i <= 20; ++i) cout << answer(i);
        cout << endl;

    }
}

Fraction Fraction::operator+(const Fraction &frac) {
    Fraction new_one = Fraction();
    new_one.denominator = denominator * frac.denominator;
    new_one.numerator = denominator * frac.numerator +
                        numerator    *frac.denominator;
    long long gcd = __gcd(new_one.numerator, new_one.denominator);
    new_one.numerator = new_one.numerator / gcd;
    new_one.denominator = new_one.denominator / gcd;
    return new_one;
}

Fraction &Fraction::operator*=(const Fraction &frac) {
    denominator *= frac.denominator;
    numerator *= frac.numerator;
    long long gcd = __gcd(numerator, denominator);
    numerator = numerator / gcd;
    denominator = denominator / gcd;

    return *this;
}

long long Fraction::getIntegerPart() {
    return numerator/denominator;
}

int Fraction::operator()(const int &digit) {
    long long tmp_num = numerator - denominator * getIntegerPart();

    long long res,remainder;

    for (int i=0;i<digit;i++){
        res = tmp_num * 10 / denominator;
        remainder = tmp_num * 10 % denominator;
        tmp_num = remainder;
    }

    return res;
}

ostream &operator<<(ostream &os, const Fraction &frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

istream &operator>>(istream &is, Fraction &frac) {
    char tmp;
    is >> frac.numerator >> tmp >> frac.denominator;
    return is;
}

FractionList::FractionList(const FractionList &frac) {
    if (frac.fraction)
        fraction = new Fraction(*frac.fraction);
    else
        fraction = nullptr;
    if (frac.nextFraction)
        nextFraction = new FractionList(*frac.nextFraction);
    else
        nextFraction = nullptr;
}

FractionList &FractionList::operator=(const FractionList &frac) {
    delete fraction;
    delete nextFraction;
    fraction = nullptr;
    nextFraction = nullptr;

    if (frac.fraction)
        fraction = new Fraction(*frac.fraction);
    if (frac.nextFraction){
        nextFraction = new FractionList(*frac.nextFraction);
    }

    return *this;
}

FractionList::~FractionList() {
    delete fraction;
    delete nextFraction;
}

FractionList *FractionList::operation(string ope, Fraction *frac) {
    if (ope == "+"){
        nextFraction = new FractionList();
        auto tmp = nextFraction;
        tmp->fraction = new Fraction(*frac);
        return tmp;
    }
    *fraction *= *frac;
    return this;
}

Fraction FractionList::getResult() {
    if (nextFraction)
        *fraction = *fraction + nextFraction->getResult();
    return *fraction;
}