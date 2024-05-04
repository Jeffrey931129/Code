#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
//#include "function.h"
using namespace std;

class Fraction {
    private:
        long long numerator;
        long long denominator;

        // Parses and returns the numerator from a string representation of a fraction.
        static long long parseNumerator(const string& frac) {
            size_t pos = frac.find('/');
            return stoll(frac.substr(0, pos));
        }

        // Parses and returns the denominator from a string representation of a fraction.
        static long long parseDenominator(const string& frac) {
            size_t pos = frac.find('/');
            long long den = stoll(frac.substr(pos + 1));
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
        // Stream extraction operator that inputs the fraction from an input stream 
        // in the form "numerator/denominator".
        //
        // Example.
        // --> Fraction f;
        //     cin >> f;                      // 6/7 (numerator = 6, denominator = 7)
        friend istream& operator>>(istream& is, Fraction& frac);

        /* ***** TODO ***** */
        // Compares this Fraction to another Fraction
        // to determine if it is (< / > / <= / >=) the other.
        bool operator<(const Fraction& frac);
        bool operator>(const Fraction& frac);
        bool operator<=(const Fraction& frac);
        bool operator>=(const Fraction& frac);

        void debug(){
            cout<<numerator<<"/"<<denominator<<endl;
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
        FractionList(const FractionList& fraclist);

        /* ***** TODO ***** */
        // Assigns a new value to the FractionList object, replacing its current contents,
        // and properly disposing of the old contents.
        // Notice: Adding "return *this" allows the operator to return a reference to the object itself. 
        // It supports chaining multiple assignments together in a single statement (e.g. A = B = C), 
        // as each assignment operation can then be followed by another, 
        // using the result of the previous assignment.
        FractionList& operator=(const FractionList& fraclist);

        /* ***** TODO ***** */
        // Adds a new Fraction to the end of the linked list.
        // This operator takes a Fraction object as input and appends it
        // to the end of the current FractionList.
        // Traverse through the entire list to reach the last element, 
        // ensuring the new Fraction is added at the end.
        FractionList& operator+=(const Fraction& frac);

        /* ***** TODO ***** */
        // Destructor that recursively deletes all fractions in the list to prevent memory leaks.
        ~FractionList();

        /* ***** TODO ***** */
        // At the end of all + operations, 
        // traverse through the FractionList and summing them up to compute the final result.
        //
        // Hint.
        // --> Use the "+" operator, which has been overloaded to add fractions, 
        //     to perform the addition of the fractions in the list.
        Fraction getResult();

        void debug(){
            cout<<"---------"<<endl;
            fraction->debug();
            FractionList* temp=nextFraction;
            while(temp){
                temp->fraction->debug();
                temp=temp->nextFraction;
            }
            cout<<"---------"<<endl;
        }
};

int main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {

        Fraction fraction;
        string comp, ope;

        cin >> fraction;
        FractionList *leftFraction = new FractionList(new Fraction(fraction));
        while (cin >> ope) {
            if (ope != "+") {
                comp = ope;
                break;
            }
            cin >> fraction;
            *leftFraction += fraction;
        }

        cin >> fraction;
        FractionList *rightFraction = new FractionList(new Fraction(fraction));
        while (cin >> ope) {
            if (ope != "+") break;
            cin >> fraction;
            *rightFraction += fraction;
        }
        //leftFraction->debug(); rightFraction->debug();
        FractionList *leftSum = new FractionList(*leftFraction);
        FractionList *rightSum = new FractionList(*rightFraction);
        //leftSum->debug(); rightSum->debug();
        FractionList answer;
        Fraction left = (answer = *leftSum).getResult();
        Fraction right = (answer = *rightSum).getResult();

        delete leftFraction, rightFraction, leftSum, rightSum;
        left.debug(); right.debug();
        if (comp == "<") cout << (left < right ? "True" : "False") << endl;
        else if (comp == ">") cout << (left > right ? "True" : "False") << endl;
        else if (comp == "<=") cout << (left <= right ? "True" : "False") << endl;
        else if (comp == ">=") cout << (left >= right ? "True" : "False") << endl;
        else cout << "Unknown operator" << endl;
    }
}

Fraction Fraction::operator+(const Fraction& frac){
    long long num=numerator*frac.denominator+denominator*frac.numerator,denom=denominator*frac.denominator;
    long long gcd=__gcd(num,denom);
    num/=gcd,denom/=gcd;
    return Fraction(num,denom);
}
istream& operator>>(istream& is, Fraction& frac){
    char c;
    is>>frac.numerator>>c>>frac.denominator;
    return is;
}
bool Fraction::operator<(const Fraction& frac){
    return numerator*frac.denominator<denominator*frac.numerator;
}
bool Fraction::operator>(const Fraction& frac){
    return numerator*frac.denominator>denominator*frac.numerator;
}
bool Fraction::operator<=(const Fraction& frac){
    return numerator*frac.denominator<=denominator*frac.numerator;
}
bool Fraction::operator>=(const Fraction& frac){
    return numerator*frac.denominator>=denominator*frac.numerator;
}
FractionList::FractionList(const FractionList& fraclist){
    fraction=new Fraction(*fraclist.fraction);
    if(fraclist.nextFraction) nextFraction=new FractionList(*fraclist.nextFraction);
    else nextFraction=nullptr;
}
FractionList& FractionList::operator=(const FractionList& fraclist){
    fraction=fraclist.fraction;
    nextFraction=fraclist.nextFraction;
    return *this;
}
FractionList& FractionList::operator+=(const Fraction& frac){
    FractionList* temp=this;
    while(temp->nextFraction) temp=temp->nextFraction; 
    temp->nextFraction=new FractionList(new Fraction(frac));
    //debug();
    return *this;
}
FractionList::~FractionList(){
    if(fraction) delete fraction;
    if(nextFraction) delete nextFraction;
}
Fraction FractionList::getResult(){
    if(nextFraction) return *fraction+nextFraction->getResult();
    else return *fraction;
}