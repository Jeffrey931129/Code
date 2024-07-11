#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int n, p[100000];

long long solve() {
    long long hold = -2e9, notHold = 0;
    for (int i=0; i<n; i++) {
        long long now_hold = MAX(hold, notHold - p[i]);
        long long now_notHold = MAX(notHold, hold + p[i]);
        hold = now_hold, notHold = now_notHold;
    }
    return notHold;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", p+i);
    printf("%lld\n", solve());
}