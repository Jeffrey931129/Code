#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,v[30],compare(const void*,const void*);  // v[i]=0代表最優先
char s[10],temp;  
int main()
{
    scanf("%d",&n);
    for(int i=0;i<26;i++)
    {
        scanf(" %c",&temp);
        v[temp-'a']=i;
    }
    while(n--)
    {
        scanf(" %s",s);
        qsort(s,6,sizeof(char),compare);
        printf("%s",s);
        if(n) printf(" ");
        else printf("\n");
    }
}

int compare(const void* x,const void* y)
{
    return v[*(const char*)x-'a']-v[*(const char*)y-'a'];
}