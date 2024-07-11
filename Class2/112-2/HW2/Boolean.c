#include <stdio.h>

int a,b,c,d,ans,pos,solve();
char s[35];
int main()
{
    scanf("%s",s);
    for(;a<2;a++) for(b=0;b<2;b++) for(c=0;c<2;c++) for(d=0;d<2;d++)
    {
        pos=0; printf("%d %d %d %d %d\n",a,b,c,d,ans=solve());
    }
}

int solve()
{
    int left=0,right=0;
    char op=s[pos++];
    if(s[pos]=='A') left=a;
    else if(s[pos]=='B') left=b;
    else if(s[pos]=='C') left=c;
    else if(s[pos]=='D') left=d;
    else left=solve();
    pos++;
    if(s[pos]=='A') right=a;
    else if(s[pos]=='B') right=b;
    else if(s[pos]=='C') right=c;
    else if(s[pos]=='D') right=d;
    else right=solve();
    return op=='&'?left&right:left|right;
}