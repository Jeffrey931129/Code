#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 505 

int record[MAXN][MAXN];
char s[MAXN];

int solve()
{
    int left_num=0,right_num=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
        {
            left_num++;
        }
        if(s[i]==')')
        {
            right_num++;
        }
        if(right_num>left_num)
        {
            return 0;
        }
    }
    if(left_num==right_num)
    {
        return 1;
    }
    return 0;
}

int main () {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0;i < MAXN; ++i)
            for (int j = 0;j < MAXN; ++j)
                record[i][j] = -1;
        scanf("%s", s);
        int flag = solve();
        printf(flag ? "Yes\n" : "No\n");
    }
    return 0;
}