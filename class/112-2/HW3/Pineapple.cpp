#include<bits/stdc++.h>
//#include "function.h"
using namespace std;

enum Gender {
    MALE,
    FEMALE
};

const string table[2] = {"MALE", "FEMALE"};

class Person {
    public:
        string name;
        int age;
        Gender gender;
        string personality;
        Person *parentA, *parentB, *mate, *child;

        Person() {
            this->name = "";
            this->age = 0;
            this->gender = MALE;
            this->personality = "";
            this->parentA = nullptr;
            this->parentB= nullptr;
            this->mate = nullptr;
            this->child = nullptr;
        }
        void describe(string* arr, int now, int len)
        {
            if(arr[now]=="ParentA")
            {
                if(parentA==nullptr) parentA=new Person(); now++; parentA->child=this;
                if(parentB!=nullptr) parentA->mate=parentB,parentB->mate=parentA;
                if(now!=len-2) parentA->describe(arr,now,len);
                else 
                {
                    if(arr[now]=="Name") parentA->name=arr[now+1];
                    else if(arr[now]=="Age") parentA->age=stoi(arr[now+1]);
                    else if(arr[now]=="Gender") if(arr[now+1]=="MALE") parentA->gender=MALE; else parentA->gender=FEMALE;
                    else
                    {
                        if(!parentA->personality.empty()) parentA->personality+=" ";
                        parentA->personality+=arr[now+1];
                    } 
                }
            } 
            else if(arr[now]=="ParentB") 
            {
                if(parentB==nullptr) parentB=new Person(); now++; parentB->child=this;
                if(parentA!=nullptr) parentB->mate=parentA,parentA->mate=parentB;
                if(now!=len-2) parentB->describe(arr,now,len);
                else 
                {
                    if(arr[now]=="Name") parentB->name=arr[now+1];
                    else if(arr[now]=="Age") parentB->age=stoi(arr[now+1]);
                    else if(arr[now]=="Gender") if(arr[now+1]=="MALE") parentB->gender=MALE; else parentB->gender=FEMALE;
                    else
                    {
                        if(!parentB->personality.empty()) parentB->personality+=" ";
                        parentB->personality+=arr[now+1];
                    } 
                }
            }
            else if(arr[now]=="Mate") 
            {
                if(mate==nullptr) mate=new Person(); now++; mate->mate=this;
                if(child!=nullptr) 
                {
                    mate->child=child;
                    if(this==child->parentA) child->parentB=mate;
                    else if(this==child->parentB) child->parentA=mate;
                }
                if(now!=len-2) mate->describe(arr,now,len);
                else 
                {
                    if(arr[now]=="Name") mate->name=arr[now+1];
                    else if(arr[now]=="Age") mate->age=stoi(arr[now+1]);
                    else if(arr[now]=="Gender") if(arr[now+1]=="MALE") mate->gender=MALE; else mate->gender=FEMALE;
                    else
                    {
                        if(!mate->personality.empty()) mate->personality+=" ";
                        mate->personality+=arr[now+1];
                    } 
                }
            }
            else 
            {
                if(child==nullptr) child=new Person(); now++;
                if(child->parentA==nullptr&&child->parentB==nullptr) 
                {
                    child->parentA=this;
                    if(mate!=nullptr) child->parentB=mate,mate->child=child;
                }
                else if(child->parentB==nullptr&&this!=child->parentA) child->parentB=this;
                else if(child->parentB==nullptr&&this==child->parentA&&mate!=nullptr) child->parentB=mate,mate->child=child;
                else if(child->parentA==nullptr&&this!=child->parentB) child->parentA=this;
                else if(child->parentA==nullptr&&this==child->parentB&&mate!=nullptr) child->parentA=mate,mate->child=child;
                if(now!=len-2) child->describe(arr,now,len);
                else 
                {
                    if(arr[now]=="Name") child->name=arr[now+1];
                    else if(arr[now]=="Age") child->age=stoi(arr[now+1]);
                    else if(arr[now]=="Gender") if(arr[now+1]=="MALE") child->gender=MALE; else child->gender=FEMALE;
                    else
                    {
                        if(!child->personality.empty()) child->personality+=" ";
                        child->personality+=arr[now+1];
                    } 
                }
            }
        }
        Person* getRelative (string* arr, int now, int len)
        {
            if(arr[now]=="ParentA")
            {
                if(parentA==nullptr) parentA=new Person(); now++; parentA->child=this;
                if(parentB!=nullptr) parentA->mate=parentB,parentB->mate=parentA;
                if(now!=len) return parentA->getRelative(arr,now,len);
                return parentA;
            } 
            else if(arr[now]=="ParentB") 
            {
                if(parentB==nullptr) parentB=new Person(); now++; parentB->child=this;
                if(parentA!=nullptr) parentB->mate=parentA,parentA->mate=parentB;
                if(now!=len) return parentB->getRelative(arr,now,len);
                return parentB;
            }
            else if(arr[now]=="Mate") 
            {
                if(mate==nullptr) mate=new Person(); now++; mate->mate=this;
                if(child!=nullptr) 
                {
                    mate->child=child;
                    if(this==child->parentA) child->parentB=mate;
                    else if(this==child->parentB) child->parentA=mate;
                }
                if(now!=len) return mate->getRelative(arr,now,len);
                return mate;
            }
            else 
            {
                if(child==nullptr) child=new Person(); now++;
                if(child->parentA==nullptr&&child->parentB==nullptr) 
                {
                    child->parentA=this;
                    if(mate!=nullptr) child->parentB=mate,mate->child=child;
                }
                else if(child->parentB==nullptr&&this!=child->parentA) child->parentB=this;
                else if(child->parentB==nullptr&&this==child->parentA&&mate!=nullptr) child->parentB=mate,mate->child=child;
                else if(child->parentA==nullptr&&this!=child->parentB) child->parentA=this;
                else if(child->parentA==nullptr&&this==child->parentB&&mate!=nullptr) child->parentA=mate,mate->child=child;
                if(now!=len) return child->getRelative(arr,now,len);
                return child;
            }
        }
        string info() {
            return 
                "Name:" + this->name + ",\n" + 
                "Age:" + to_string(this->age) + ",\n" +
                "Gender:" + table[this->gender] + ",\n" +
                "Personality:" + this->personality + "\n\n";
        };
};
string* ParseStatement(string statement) { // return the parsed array
    stringstream ss;
    vector<string> v;
    ss << statement;
    while (ss >> statement) v.push_back(statement);
    string* ret = new string[v.size()];
    for (int _ = 0; _ < v.size(); ++_) {
        ret[_] = v[_];
    }
    return ret;
}

int getParseStatementLength(string statement) {
    stringstream ss;
    ss << statement;
    int ret = 0;
    while (ss >> statement) ++ret;
    return ret;
}

int main () {
    Person* narrator = new Person();

    narrator->name = "Pineapple Senpai";
    narrator->age = 21;
    narrator->gender = MALE;
    narrator->personality = "seasick";

    int Q;
    cin >> Q;
    for (int _ = 0; _ < Q; ++_) {
        // input type of the query
        int type;
        cin >> type;
        // get the parsed array
        string statement;
        getline(cin, statement);
        string* arr = ParseStatement(statement);
        // compute the length of the array
        int len = getParseStatementLength(statement);
        switch(type) {
            case 1: 
                narrator = narrator->getRelative(arr, 0, len);
                break;
            case 2: 
                narrator->describe(arr, 0, len);
                break;
            case 3:
                cout << narrator->info() << "\n";
                break;
        }
        delete[] arr;
    }
    return 0;
}
