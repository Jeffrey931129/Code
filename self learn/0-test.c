#include <stdio.h>

void function(int*);
int main() {
    int n=0;
    printf("before funtion : %d\n",n);
    function(&n);
    printf("after funtion : %d",n);
    return 0;
}

void function(int *p)
{
    *p=1;
    return;
}