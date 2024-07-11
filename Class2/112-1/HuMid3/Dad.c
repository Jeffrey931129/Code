#include <stdio.h>
#include <string.h>

int k,rec;
char s[1000005];
void mystrcpy(int idx);
int main()
{
    scanf("%s",s);
    scanf("%d",&k);
    int lenth=strlen(s),pick=k;
    while(k&&s[rec]!=0)
    {
        if(s[rec+k]==0) break;
        int small=s[rec],idx=rec,i=rec;
        for(;i<=rec+k&&s[i]!=0;i++)
        {
            if(s[i]<small)
            {
                small=s[i]; idx=i;
            }
            if(small=='0') break;
        }
        mystrcpy(idx);
        k-=idx-rec; rec++;
    }
    int zero=0;
    for(int i=0;i<lenth-pick;i++)
    {
        if(!zero&&s[i]=='0') continue;
        zero=1;
        printf("%c",s[i]);
    }
    if(!zero) printf("0");
    puts("");
    return 0;
}

void mystrcpy(int idx)
{
    int i=0;
    for(;s[idx+i]!=0;i++)
    {
        s[rec+i]=s[idx+i];
    }
    s[rec+i]=0; return;
}