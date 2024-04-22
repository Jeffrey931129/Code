#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <bitset>
#include <fstream>
using namespace std;

string decimalToBinary(int decimal,int var_num){
    return bitset<12>(decimal).to_string().substr(12-var_num);
}

int main()
{
    srand(time(NULL));
    int var_num=rand()%12+1;
    int range=pow(2,var_num);
    int store[range],rec=0;
    for(int i=0;i<range;i++){
        int rate=rand()%3;
        if(!rate) store[rec++]=i;
    }
    //ifstream in();
    ofstream out("Example.txt");
    out<<var_num<<endl<<rec<<endl;
    for(int i=0;i<rec;i++){
        string temp=decimalToBinary(store[i],var_num);
        out<<temp<<endl;
    }
}