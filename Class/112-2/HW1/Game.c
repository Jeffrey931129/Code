#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int s[n];
        for(int i=0;i<n;i++) s[i]=i+1;
        while(k--)
        {
            int a;
            scanf("%d",&a);
            if(s[a-1]>=n) printf("Penguin07 QQ\n");
            else
            {
                printf("%d\n",s[a-1]+1);
                int temp=s[s[a-1]];
                s[s[a-1]]=n,s[a-1]=temp;
            } 
            
        }
    }
}