#include <stdio.h>

int f[81],g[81],n;
int fib(int);
int gib(int);
int main()
{
    scanf("%d%d%d%d%d",&f[0],&f[1],&g[0],&g[1],&n);
    for(int i=2;i<=n;i++)
    {
        f[i]=fib(i);
    }
    printf("%d %d\n",fib(n),gib(n));
    
    return 0;
}

int fib(int n)
{
    if(n==1) return f[1];
    if(n==0) return f[0];
    if(f[n]!=0) return f[n];
    if(n%3==0) 
    {
        if(f[n-1]==0)
        {
            f[n-1]=fib(n-1);
        }
        if(f[n/3]==0)
        {
            f[n/3]=fib(n/3);
        }
        if(g[f[n/3]]==0)
        {
            g[f[n/3]]=gib(f[n/3]);
        }
        return f[n-1]+g[f[n/3]];
    }
    else 
    {
        if(f[n-1]==0)
        {
            f[n-1]=fib(n-1);
        }
        if(g[n-2]==0)
        {
            g[n-2]=gib(n-2);
        }
        return f[n-1]+g[n-2];
    }
    
}

int gib(int n)
{
    if(n==1) return g[1];
    if(n==0) return g[0];
    if(g[n]!=0) return g[n];
    if(n%5==0)
    {
        if(g[n-1]==0)
        {
            g[n-1]=gib(n-1);
        }
        if(g[n/5]==0)
        {
            g[n/5]=gib(n/5);
        }
        if(f[g[n/5]]==0)
        {
            f[g[n/5]]=fib(g[n/5]);
        }
        return g[n-1]+f[g[n/5]];
    }
    else 
    {
        if(g[n-1]==0)
        {
            g[n-1]=gib(n-1);
        }
        if(f[n-2]==0)
        {
            f[n-2]=fib(n-2);
        }
        return g[n-1]+f[n-2];
    }
    
}