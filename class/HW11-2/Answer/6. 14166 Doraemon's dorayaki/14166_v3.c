#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int n, p[100000];

long long solve() {
    long long profit = 0;
    for (int i=1; i<n; i++) {
        profit += MAX(0, p[i] - p[i-1]);
    }
    return profit;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", p+i);
    printf("%lld\n", solve(0, 0));
}