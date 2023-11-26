#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000001],save[100000][2];
    scanf("%s",s);
    int q,change[26];
    scanf("%d",&q);
    for(int i=0;i<26;i++)
    {
        change[i]=i;
    }
    for(int i=0;i<q;i++)
    {
        
        scanf(" %c %c",&save[i][0],&save[i][1]);

    }
    for(int i=q-1;i>=0;i--)
    {
        change[save[i][0]-'a']=change[save[i][1]-'a'];
    }
    int word=strlen(s);
    for(int i=0;i<word;i++)
    {
        s[i]=change[s[i]-'a']+'a';
    }

    printf("%s\n",s);
    return 0;
}