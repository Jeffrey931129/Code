#include <stdio.h>

int f[81],g[81],n;
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
    if(n=1) return f[1];
    if(n=0) return f[0];
    if(f[n]!=0) return f[n];
    if(n%3==0) return fib(n-1)+gib(n/3);
    else return fib(n-1)+gib(n-2);
}

int gib(int n)
{
    if(n=1) return g[1];
    if(n=0) return g[0];
    if(g[n]!=0) return g[n];
    if(n%5==0) return gib(n-1)+fib(n/5);
    else return gib(n-1)+fib(n-2);
}