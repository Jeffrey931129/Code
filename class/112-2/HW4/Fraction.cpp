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

Fraction Fraction::operator+(const Fraction& frac){
    long long denom=denominator*frac.denominator;
    long long num=numerator*frac.denominator+frac.numerator*denominator;
    long long gcd = __gcd(num, denom);
    num/=gcd,denom/=gcd;
    return Fraction(num,denom);
}
// Fraction Fraction::operator+(const Fraction& frac){
//     long long denom=lcm(denominator,frac.denominator);
////   long long num=denom/denominator*numerator+denom/frac.denominator*frac.numerator;
//     long long gcd = __gcd(num, denom);
//     num/=gcd,denom/=gcd;
//     return Fraction(num,denom);
// }                                       原本寫法

Fraction& Fraction::operator*=(const Fraction& frac){
    Fraction temp=frac;
    numerator*=temp.numerator,denominator*=temp.denominator;
    long long gcd=__gcd(numerator,denominator);
    numerator/=gcd,denominator/=gcd;
    if(numerator==0) denominator=1;
    return *this;
}
// Fraction& Fraction::operator*=(const Fraction& frac){
//     Fraction temp=frac;
//     long long gcd=__gcd(numerator,temp.denominator);
//     numerator/=gcd,temp.denominator/=gcd;
//     gcd=__gcd(temp.numerator,denominator);
//     temp.numerator/=gcd,denominator/=gcd;
//     numerator*=temp.numerator,denominator*=temp.denominator;
////   gcd=__gcd(numerator,denominator);
////   numerator/=gcd,denominator/=gcd; 
//     if(numerator==0) denominator=1;
//     return *this;
// }                                       原本寫法

long long Fraction::getIntegerPart(){
    return numerator/denominator;
}

int Fraction::operator()(const int& digit){
    long long remainder = numerator % denominator;
    for (int i = 1; i < digit; ++i) {
        remainder *= 10;
        remainder %= denominator;
    }
    return remainder * 10 / denominator;
}

ostream& operator<<(ostream& os, const Fraction& frac){
    os<<frac.numerator<<"/"<<frac.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& frac){
    char c;
    is>>frac.numerator>>c>>frac.denominator;
    return is;
}

FractionList::FractionList(const FractionList& frac){
    fraction=new Fraction(1,1);
    *fraction*=*frac.fraction;
    if(frac.nextFraction!=NULL){
        nextFraction=new FractionList(*frac.nextFraction);
    }
    else nextFraction=NULL;
}

FractionList& FractionList::operator=(const FractionList& frac){
    fraction=frac.fraction,nextFraction=frac.nextFraction;
    return *this;
}

FractionList::~FractionList(){
    delete fraction;
    if(nextFraction!=NULL) delete nextFraction;
}

FractionList* FractionList::operation(string ope, Fraction *frac){
    if(ope=="*"){
        *fraction*=*frac;
        return this;
    }
    else{
        FractionList* temp=new FractionList(frac);
        this->nextFraction=temp;
        return temp;
    }
}
Fraction FractionList::getResult(){
    if(nextFraction!=NULL) return *fraction+nextFraction->getResult();
    else return *fraction;
}