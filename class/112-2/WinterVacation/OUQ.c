#include <stdio.h>
#include <math.h>

long long n,l,r,rec[50];
char find(long long n,long long l);
int main()
{
    rec[1]=3;
    for(int i=2;i<=50;i++)
    {
        rec[i]=rec[i-1]*2+3;
    }
    while(scanf("%lld%lld%lld",&n,&l,&r)!=EOF)
    {
        for(;l<=r;l++)
        {
            printf("%c",find(n,l));
        }
        printf("\n");
    }
}

char find(long long n,long long l)
{
    if(l==0) return 'O';
    else if(l==rec[n]/2) return 'u';
    else if(l==rec[n]-1) return 'Q';
    else if(l>0&&l<rec[n]/2) return find(n-1,l-1);
    else if(l>rec[n]/2&&l<rec[n]-1) return find(n-1,l-rec[n]/2-1);
}