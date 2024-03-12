#include <stdio.h>

char s[260];
int rec[260];
int main()
{
    scanf("%s",s);
    int pos=0,part=0;
    while(s[pos]=='('||s[pos]==')')
    {
        if(s[pos]=='(')
        {
            rec[part++]=1;
            s[pos]=1;
        }
        else
        {
            rec[--part]=0;
            s[pos]=1;
        }
        pos++;
    }
    while(s[pos]!=0)
    {
        if(s[pos]=='(')
        {
            if(s[pos-1]==s[pos]||s[pos-1]==1) rec[part++]=1,s[pos]=1;
            else part++;
        }
        else if(s[pos]==')')
        {
            if(rec[--part]) s[pos]=1,rec[part]=0;
        }
        pos++;
    }
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]!=1) printf("%c",s[i]);
    }
}