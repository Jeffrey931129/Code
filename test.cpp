#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

int num;
int store[100000]={0};
int main()
{
    int rec=0;
    while(cin>>num&&!cin.eof()){
        string temp=to_string(num);
        for(int i=0;i<temp.size();i++){
            if(temp[temp.size()-1-i]=='1') store[rec]+=pow(2,i);
        }
        rec++;
    }
    for(int i=0;i<rec;i++){
        cout<<store[i]<<",";
    }
}
