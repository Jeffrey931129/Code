#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <utility>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;


class QM{
private:
    int max=999999999;
    int var_num;
    int term_num;
    int prime_num;
    int* essential;     // 1 is essential
    int** chart;
    int* non_cover_minterm;     // 0 is need to be considered, -1 is not need

    vector<string> minterm;     // store minterm
    vector<string> prime;       // prime after QM 
    vector<string> out_prime;   // final output prime 
    vector<string> out_prime_temp;


public:

    bool hit(string &a, string &b, string &out){
        // check whether a and b can be merged 
        // if can merge, return true and store the merged term in out
        int flag = 0, index = -1;
        for(int i = 0; i < a.length();i++){
            if(a[i]!=b[i]){
                if(flag==0){
                    flag = 1;
                    index = i;
                }
                else{
                    return false;
                }
            }
        }
        out = a;
        out[index] = '-';
        return true;
    }
    
    void init(ifstream &in){
        // read input from file
        in>>var_num;
        in>>term_num;
        string temp;
        for(int i = 0; i < term_num; i++){
            in>>temp;
            minterm.push_back(temp);
            prime.push_back(temp);
        }
    }
    
    void merge_implicants(){
        // Merges groups of minterms with one difference into a single term with a dash ("-").
        static int i=0,j=term_num;
        int rec[5000]={0},end=j,start=i;  
        for(;i<end;i++){
            for(int k=i+1;k<end;k++){
                int diff=0,pos=0;
                for(int l=0;l<var_num;l++){
                    if(prime[i][l]^prime[k][l]) diff++,pos=l;
                }
                if(diff==1){
                    string temp=prime[i]; temp[pos]='-';
                    int done=1;
                    for(int l=end;l<j;l++){
                        if(prime[l]==temp){
                            done=0; break;
                        }
                    }
                    if(done){
                        prime.push_back(temp); j++;
                    }
                    rec[i]=rec[k]=1; 
                }
            }
        }
        for(;--end>=start;){
            if(rec[end]){
                prime.erase(prime.begin()+end);
                i--; j--;
            }
        }
    }
    

    void find_prime_implicants(){
        int time = 0;
        while(time <= var_num){
            merge_implicants();
            time++;
            cout<<time<<" : "<<endl;
            for(int i=0;i<prime.size();i++){
                cout<<prime[i]<<endl;
            }
        }
    }

    void create_array(){
        prime_num=prime.size();
        essential=new int[prime_num]{0};
        chart=new int*[term_num];
        for(int i=0;i<term_num;i++) chart[i]=new int[prime_num]{0};
        non_cover_minterm=new int[term_num]{0};
    }

    void find_essential_prime_implicants(){
        // Finds essential prime implicants from the prime implicants.
        create_array();
        //cout<<"create array"<<endl;
        for(int i=0;i<term_num;i++){
            int rec=0,l=0;
            for(int j=0;j<prime_num;j++){
                int check=0;
                for(int k=0;k<var_num;k++){
                    if(prime[j][k]!='-'&&minterm[i][k]!=prime[j][k]){
                        check++; break;
                    }
                }
                if(!check) rec++,l=j,chart[i][j]=1;
            }
            if(rec==1){
                essential[l]=1;
            }
        }
        //cout<<"1"<<endl;
        for(int i=0;i<term_num;i++){
            int check=0;
            for(int j=0;j<prime_num;j++){
                if(essential[j]&&chart[i][j]){
                    check=1; break;     // check==1 essential cover
                }
            }
            if(check) non_cover_minterm[i]=-1;
        }
        //cout<<prime_num<<endl;
        cout<<"essential:"<<endl;
        for(int i=0;i<prime_num;i++) cout<<essential[i]<<" ";
        puts("");
        cout<<"non_cover:"<<endl;
        for(int i=0;i<term_num;i++) cout<<non_cover_minterm[i]<<" ";
        puts("");
        //cout<<"2"<<endl;
    }


    void find_min_cover(){
        // Finds the minimum cover of the left minterms 
        // after finding the essential prime implicants.
        //cout<<"3"<<endl;
        search(0);
        for(int i=0;i<prime_num;i++) if(essential[i]) out_prime.push_back(prime[i]);
        cout<<"answer:"<<endl;
        for(int i=0;i<out_prime.size();i++) cout<<out_prime[i]<<endl;
    }

    void search(int term_pos){
        //for(int i=0;i<out_prime_temp.size();i++) cout<<out_prime_temp[i]<<endl;
        //for(int i=0;i<term_num;i++) cout<<non_cover_minterm[i]<<" ";
        //puts("");
        //cout<<"--------------"<<endl;
        int yes=1;
        for(int i=0;i<term_num;i++){
            if(!non_cover_minterm[i]){
                yes=0; break;
            }
        }
        if(yes){
            int temp=0;
            for(int i=0;i<out_prime_temp.size();i++) temp+=var_num-count(out_prime_temp[i].begin(), out_prime_temp[i].end(), '-');
            if(temp<max){
                max=temp;
                out_prime.clear();
                out_prime=out_prime_temp;
            }
            return;
        }
        int i=term_pos;
        while(i<term_num&&non_cover_minterm[i]) i++;
        if(i==term_num) return;
        for(int j=prime_num-1;j>=0;j--){
            if(!chart[i][j]) continue;
            int rec[term_num]={0};
            for(int k=0;k<term_num;k++) if(chart[k][j]&&!non_cover_minterm[k]) rec[k]=1,non_cover_minterm[k]=1;
            out_prime_temp.push_back(prime[j]);
            search(i+1);
            out_prime_temp.pop_back();
            for(int k=0;k<term_num;k++) if(rec[k]) non_cover_minterm[k]=0;
        }
    }

    bool check_equal(){
        // check whether the out prime implicants are equal to the minterms
        // if equal, return true
        // Please remain vector minterm unchanged and store the result in vector out_prime before call this function

        queue<string> q;
        unordered_set<string> temp;
        unordered_map<string, bool> mp, mp2;
        for(string &a : minterm){
            mp[a] = true;
        }
        for(string &a : out_prime){  
            if(!mp2[a]){
                q.push(a);
                mp2[a] = true;
            }
        }
        while(!q.empty()){
            string a = q.front();
            q.pop();
            
            int i = 0;
            for(i = 0; i < a.length(); i++){
                if(a[i]=='-'){
                    string b = a;
                    b[i] = '0';
                    q.push(b);
                    b[i] = '1';
                    q.push(b);
                    break;
                }
            }
            if(i == a.length()){
                if(mp[a]){
                    temp.insert(a);
                }
                else{
                    cout<<"output prim cover more than minterm"<<endl;
                    cout<<"output prime implicants are not equal to the minterms\n"<<endl;
                    return false;
                }
            }
        }
        if(temp.size() == minterm.size()){
            cout<<"output prime implicants are equal to the minterms\n"<<endl;
            return true;
        }
        else{
            // cout<<"minterm size : "<<minterm.size()<<endl;
            // cout<<"Output prime expand minterm size : "<<temp.size()<<endl;
            cout<<"output prime implicants are not equal to the minterms\n"<<endl;
            
            return false;
        }
        
    }
    
    void output_prime(ofstream & out){
        int litteral_count = 0;
        for(string &a : out_prime){
            litteral_count+= var_num - count(a.begin(), a.end(), '-');
        }
        out<<litteral_count<<endl<<out_prime.size()<<endl;
        for(string &a : out_prime){
            out<<a<<endl;
        }
    }

    void free(){
        delete[] essential;
        delete[] non_cover_minterm;
        for(int i=0;i<term_num;i++) delete[] chart[i];
        delete[] chart;
    }
};

int main(int argc, char* argv[]){
    QM qm;
    
    // command example: ./main ../testcase/case00.in ../output/case00.out

    
    
    ifstream in(argv[1]);
    ofstream out(argv[2]);

    // read input from file
    qm.init(in);

    // Finds the prime implicants from the minterms.
    qm.find_prime_implicants();                             // done

    // Finds essential prime implicants from the prime implicants.
    qm.find_essential_prime_implicants();

    // Finds the minimum cover of the left minterms 
    // after finding the essential prime implicants.
    qm.find_min_cover();

    // check whether the out prime implicants are equal to the minterms
    // Please remain vector minterm unchanged and store the result in vector out_prime before call this function
    qm.check_equal();

    qm.output_prime(out);

    qm.free();
    
    return 0;
}