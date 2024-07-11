#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char f0[2020], f1[2020];
long long int len[100];

char f(int n, long long int k) {
    // basis step
    if (n == 0) return f0[k];
    if (n == 1) return f1[k];
    // recursive step
    if (k >= len[n-2]) return f(n-1, k-len[n-2]);
    else return f(n-2, k);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long int n, k;
        scanf("%s %s %lld %lld", f0, f1, &n, &k);

        // get the lengths of F0, F1.
        len[0] = strlen(f0), len[1] = strlen(f1);
        // calculate the lengths of F2, ..., Fn.
        for (int i = 2; i <= n; i++)
            len[i] = len[i-1] + len[i-2];

        char ans = f(n, k);
        printf("%c\n", ans);
    }
}
