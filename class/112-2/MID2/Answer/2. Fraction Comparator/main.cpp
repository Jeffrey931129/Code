#include <iostream>
#include <string>
#include "function.h"
using namespace std;

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
        
        FractionList *leftSum = new FractionList(*leftFraction);
        FractionList *rightSum = new FractionList(*rightFraction);
        FractionList answer;
        Fraction left = (answer = *leftSum).getResult();
        Fraction right = (answer = *rightSum).getResult();

        delete leftFraction, rightFraction, leftSum, rightSum;

        if (comp == "<") cout << (left < right ? "True" : "False") << endl;
        else if (comp == ">") cout << (left > right ? "True" : "False") << endl;
        else if (comp == "<=") cout << (left <= right ? "True" : "False") << endl;
        else if (comp == ">=") cout << (left >= right ? "True" : "False") << endl;
        else cout << "Unknown operator" << endl;
    }
}