#include <stdio.h>
#include <string.h>

int main()
{
    char s[10005];
    scanf("%s",s);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        if(l==r) continue;
        if((k=k%(r-l+1))==0) continue;
        char temp[r-l+1];
        for(int i=0;i<k;i++) temp[i]=s[r-k+i];
        for(int i=0;i<r-l+1-k;i++)
        {
            s[r-i-1]=s[r-k-i-1];
        }
        for(int i=0;i<k;i++) s[l+i-1]=temp[i];
        //printf("%s\n",s);
    }
    printf("%s\n",s);
}