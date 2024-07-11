#include <stdio.h>
#include <string.h>

int main()
{
    char x[10002];
    while(scanf("%s",x)!=EOF)
    {
        int answer=0;
        int n=strlen(x);
        for(int i=n;i<=n;i--)   // 字數
        {
            for(int j=0,check=1;i+j<=n;j++)   // 從哪裡開始
            {
                for(int k=0;k<(i/2);k++)
                {
                    if(x[j+k]!=x[i+j-1-k])
                    {
                        check=0;
                        break;
                    }
                }
                if(check)
                {
                    answer=i;
                    break;
                }
                check=1;
            }
            if(answer!=0)
            {
                break;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}