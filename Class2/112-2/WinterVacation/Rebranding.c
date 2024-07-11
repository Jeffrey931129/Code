#include <stdio.h>

int n,m,change[26];
int main()
{
    scanf("%d%d",&n,&m);
    char arr[n+1],rec[m][2];
    for(int i=0;i<26;i++) change[i]=i;
    scanf(" %s",arr);
    for(int i=0;i<m;i++) scanf(" %c %c",&rec[i][0],&rec[i][1]);
    for(int i=m-1;i>=0;i--)
    {
        int temp=change[rec[i][0]-'a'];
        change[rec[i][0]-'a']=change[rec[i][1]-'a'];
        change[rec[i][1]-'a']=temp;
    }
    for(int i=0;i<n;i++)
        printf("%c",change[arr[i]-'a']+'a');
    puts("");
}