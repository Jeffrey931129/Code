#include <stdio.h>

#define MAX_SIZE 1000005

long long a[MAX_SIZE], b[MAX_SIZE];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        b[i] = a[i] - a[i - 1];
    }
    for(int i = 0, L, R, X; i < m; i++) {
        scanf("%d %d %d", &L, &R, &X);
        b[L] += X;
        b[R + 1] -= X;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + b[i];
        printf("%lld", a[i]);
        if(i == n)
            printf("\n");
        else
            printf(" ");
    }
}

