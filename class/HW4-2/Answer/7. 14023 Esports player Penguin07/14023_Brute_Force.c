#include <stdio.h>

#define MAX_SIZE 1000005

long long a[MAX_SIZE];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0, L, R, X; i < m; i++) {
        scanf("%d %d %d", &L, &R, &X);
        for(int j = L; j <= R; j++) {
            a[j] += X;
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%lld", a[i]);
        if(i == n)
            printf("\n");
        else
            printf(" ");
    }
}
