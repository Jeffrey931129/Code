#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char* ret = malloc(sizeof(char) * (len1 + len2 + 1));
    memset(ret, 0, len1 + len2 + 1);

    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul_ret = (num1[i] - '0') * (num2[j] - '0');
            ret[i + j + 1] += mul_ret % 10;
            while(ret[i+j+1]>=10) ret[i+j+1]-=10,ret[i+j]++;    //
            ret[i + j] += mul_ret / 10;
            while(ret[i+j]>=10) ret[i+j]-=10,ret[i+j-1]++;      //
            for(int k=0;k<len1+len2+1;k++) printf("%c",ret[k]+'0');
            puts("");
        }
    }

    for (int i = 0; i < len1 + len2 ; ++i) {     //
        ret[i] += '0';
    }

    return ret;
}

int main() {
    char num1[1001], num2[1001];

    scanf("%s %s", num1, num2);
    char* ans = multiply(num1, num2);

    while (*ans == '0') ans++;

    printf("%s\n", ans);
    free(ans);

    return 0;
}
