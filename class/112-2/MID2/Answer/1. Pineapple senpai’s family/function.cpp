#include<bits/stdc++.h>
#include "function.h"
using namespace std;

void Person::describe(string* arr, int now, int len){
    Person* final = this;
    final = getRelative(arr, 0, len);
    for(int i = 0; i < len - 1; i++){
        string goal = arr[i];
        string data = arr[i+1];
        if(goal == "Name")final->name = data;
        else if(goal == "Age")final->age = stoi(data);
        else if(goal == "Gender"){
            if(data == "MALE")final->gender = MALE;
            else final->gender = FEMALE;
        }
        else if(goal == "Personality"){
            if(final->personality == "")final->personality = data;
            else final->personality += " " + data;
        }
    }
}

Person* Person::getRelative (string* arr, int now, int len){
    Person* node = this;
    for(int i = 0; i < len; i++){
        string s = arr[i];
        if(s == "ParentA"){
            if(node->parentA == nullptr){
                node->parentA = new Person();
                node->parentA->mate = node->parentB;
                if(node->parentB != nullptr)node->parentB->mate = node->parentA;
                node->parentA->child = node;
            }
            node = node->parentA;
        }
        else if(s == "ParentB"){
            if(node->parentB == nullptr){
                node->parentB = new Person();
                node->parentB->mate = node->parentA;
                if(node->parentA != nullptr)node->parentA->mate = node->parentB;
                node->parentB->child = node;
            }
            node = node->parentB;
        }
        else if(s == "Mate"){
            if(node->mate == nullptr){
                node->mate = new Person();
                node->mate->mate = node;
                if(node->child != nullptr){
                    if(node->child->parentA == node){
                        node->mate->child = node->child;
                        node->child->parentB = node->mate;
                    }
                    else if(node->child->parentB == node){
                        node->mate->child = node->child;
                        node->child->parentA = node->mate;
                    }
                }

            }
            node = node->mate;
        }
        else if(s == "Child"){
            if(node->child == nullptr){
                node->child = new Person();
                node->child->parentA = node;
                if(node->mate != nullptr){
                    node->child->parentB = node->mate;
                    node->mate->child = node->child;
                }
            }
            node = node->child;
        }

    }
    return node;
}
