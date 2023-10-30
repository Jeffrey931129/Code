#include <stdio.h>

int f[81],g[81],n,fc[81]={1,1},gc[81]={1,1};
int fib(int);
int gib(int);
int main()
{
    scanf("%d%d%d%d%d",&f[0],&f[1],&g[0],&g[1],&n);
    
    printf("%d %d\n",fib(n),gib(n));
    
    return 0;
}

int fib(int n)
{
    
    if(n==1) return f[1];
    if(n==0) return f[0];
    if(fc[n]!=0) return f[n];
    if(n%3==0) 
    {
        f[n]=fib(n-1)+gib(fib(n/3)%n);
        fc[n]++;
        return f[n];
    }
    else 
    {
        f[n]=fib(n-1)+gib(n-2);
        fc[n]++;
        return f[n];
    }
    
}

int gib(int n)
{
    
    if(n==1) return g[1];
    if(n==0) return g[0];
    if(gc[n]!=0) return g[n];
    if(n%5==0) 
    {
        g[n]=gib(n-1)+fib(gib(n/5)%n);
        gc[n]++;
        return g[n];
    }
    else 
    {
        g[n]=gib(n-1)+fib(n-2);
        gc[n]++;
        return g[n];
    }
    
}