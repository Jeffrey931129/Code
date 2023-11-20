#include <stdio.h>
#include <string.h>

char s[1000001];
int change[26],result[26][26],rec[26],q;  // change的0代表變成a
int main()
{
    scanf("%s",s);
    scanf("%d",&q);
    for(int i=0;i<26;i++)
    {
        change[i]=i;
        rec[i]=1;
        result[i][0]=i;
    }
    while(q--)
    {
        char from,to;
        scanf(" %c %c",&from,&to);
        for(int i=0;i<rec[from-'a'];i++)
        {
            change[result[from-'a'][i]]=to-'a';
            result[to-'a'][rec[to-'a']]=result[from-'a'][i];
            rec[to-'a']++;
        }
        rec[from-'a']=0;
    }
    for(int i=0;i<strlen(s);i++)
    {
        printf("%c",change[s[i]-'a']+'a');
    }
    printf("\n");
    return 0;
}