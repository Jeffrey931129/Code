#include <stdio.h>

int p[(int)1e5+10], ans[(int)1e5+10];

void solve(int pl, int pr, int al, int ar) {
    ans[ar] = p[pl];
    if (pl+1 > pr) return;
    int pm = (pl+pr+1) >> 1, am = (al+ar-1) >> 1;
    if (p[pl] < p[pl+1]) {
        solve(pl+1, pm, am+1, ar-1);
        solve(pm+1, pr, al, am);
    } else {
        solve(pm+1, pr, am+1, ar-1);
        solve(pl+1, pm, al, am);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", p+i);
    solve(0, n-1, 0, n-1);
    for (int i=0; i<n; i++) printf((i+1<n?"%d ":"%d\n"), *(ans+i));
}