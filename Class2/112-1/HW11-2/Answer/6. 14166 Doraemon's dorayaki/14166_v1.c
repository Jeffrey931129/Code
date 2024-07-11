#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int n, p[100000];

long long solve(int x, int hold) {
    if (x >= n) return 0;
    if (!hold) {
        long long to_buy = solve(x+1, 1) - p[x];
        long long not_buy = solve(x+1, 0);
        return MAX(to_buy, not_buy);
    } else {
        long long to_sell = solve(x+1, 0) + p[x];
        long long not_sell = solve(x+1, 1);
        return MAX(to_sell, not_sell);
    }
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", p+i);
    printf("%lld\n", solve(0, 0));
}