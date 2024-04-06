#include <iostream>
#include <string>
using namespace std;

class String_Calculator 
{
    public:
        String_Calculator():ans(0){}
        void calculate(string x,string y)
        {
            size_t find=x.find(y);
            if(find!=string::npos) x.replace(find,y.length(),"");
            else x="error";
            x=x+y;
            int rec=0; find=x.find(y);
            while(find!=string::npos)
            {
                find=x.find(y,find+1);
                rec++;
            }
            ans=rec;
        }
        void printans()
        {
            cout<<ans<<endl;
        }
    private:
        int ans;
};

int main()
{
    int n; cin>>n;
    while(n--)
    {
        string x,y; cin>>x>>y;
        String_Calculator ans;
        ans.calculate(x,y);
        ans.printans();
    }
}