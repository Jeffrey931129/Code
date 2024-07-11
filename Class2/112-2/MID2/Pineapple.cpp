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
        void describe(string* arr, int now, int len);
        Person* getRelative (string* arr, int now, int len);
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

void Person::describe(string* arr, int now, int len){
    if(arr[now]=="ParentA"){
        if(!parentA){
            parentA=new Person();
            parentA->child=this;
            if(parentB) parentB->mate=parentA,parentA->mate=parentB;
        }
        now++;
        if(now!=len-2) parentA->describe(arr,now,len);
        else{
            if(arr[now]=="Gender"){
                if(arr[now+1]=="MALE") parentA->gender=MALE;
                else parentA->gender=FEMALE;
            }
            else if(arr[now]=="Age"){
                parentA->age=stoi(arr[now+1]);
            }
            else if(arr[now]=="Name"){
                parentA->name=arr[now+1];
            }
            else{
                if(parentA->personality.empty()) parentA->personality=arr[now+1];
                else parentA->personality+=" "+arr[now+1];
            }
        }
    }
    else if(arr[now]=="ParentB"){
        if(!parentB){
            parentB=new Person();
            parentB->child=this;
            if(parentA) parentA->mate=parentB,parentB->mate=parentA;
        }
        now++;
        if(now!=len-2) parentB->describe(arr,now,len);
        else{
            if(arr[now]=="Gender"){
                if(arr[now+1]=="MALE") parentB->gender=MALE;
                else parentB->gender=FEMALE;
            }
            else if(arr[now]=="Age"){
                parentB->age=stoi(arr[now+1]);
            }
            else if(arr[now]=="Name"){
                parentB->name=arr[now+1];
            }
            else{
                if(parentB->personality.empty()) parentB->personality=arr[now+1];
                else parentB->personality+=" "+arr[now+1];
            }
        }
    }
    else if(arr[now]=="Mate"){
        if(!mate){
            mate=new Person();
            mate->mate=this;
            if(child){
                mate->child=child;
                if(this==child->parentA) child->parentB=mate;
                else if(this==child->parentB) child->parentA=mate;
            }
        }
        now++;
        if(now!=len-2) mate->describe(arr,now,len);
        else{
            if(arr[now]=="Gender"){
                if(arr[now+1]=="MALE") mate->gender=MALE;
                else mate->gender=FEMALE;
            }
            else if(arr[now]=="Age"){
                mate->age=stoi(arr[now+1]);
            }
            else if(arr[now]=="Name"){
                mate->name=arr[now+1];
            }
            else{
                if(mate->personality.empty()) mate->personality=arr[now+1];
                else mate->personality+=" "+arr[now+1];
            }
        }
    }
    else if(arr[now]=="Child"){
        if(!child){
            child=new Person();
            child->parentA=this;
            if(mate) mate->child=child,child->parentB=mate;
        }
        now++;
        if(now!=len-2) child->describe(arr,now,len);
        else{
            if(arr[now]=="Gender"){
                if(arr[now+1]=="MALE") child->gender=MALE;
                else child->gender=FEMALE;
            }
            else if(arr[now]=="Age"){
                child->age=stoi(arr[now+1]);
            }
            else if(arr[now]=="Name"){
                child->name=arr[now+1];
            }
            else{
                if(child->personality.empty()) child->personality=arr[now+1];
                else child->personality+=" "+arr[now+1];
            }
        }
    }
}

Person* Person::getRelative (string* arr, int now, int len){
    if(arr[now]=="ParentA"){
        if(!parentA){
            parentA=new Person();
            parentA->child=this;
            if(parentB) parentB->mate=parentA,parentA->mate=parentB;
        }
        now++;
        if(now!=len) return parentA->getRelative(arr,now,len);
        else return parentA;
    }
    else if(arr[now]=="ParentB"){
        if(!parentB){
            parentB=new Person();
            parentB->child=this;
            if(parentA) parentA->mate=parentB,parentB->mate=parentA;
        }
        now++;
        if(now!=len) return parentB->getRelative(arr,now,len);
        else return parentB;
    }
    else if(arr[now]=="Mate"){
        if(!mate){
            mate=new Person();
            mate->mate=this;
            if(child){
                mate->child=child;
                if(this==child->parentA) child->parentB=mate;
                else if(this==child->parentB) child->parentA=mate;
            }
        }
        now++;
        if(now!=len) return mate->getRelative(arr,now,len);
        else return mate;
    }
    else if(arr[now]=="Child"){
        if(!child){
            child=new Person();
            child->parentA=this;
            if(mate) mate->child=child,child->parentB=mate;
        }
        now++;
        if(now!=len) return child->getRelative(arr,now,len);
        else return child;
    }
}