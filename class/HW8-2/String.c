#include <stdio.h>
#include <string.h>

char s[1000001];
int change[26],q;  // change的1代表變成a
int main()
{
    scanf("%s",s);
    scanf("%d",&q);
    for(int i=0;i<26;i++)
    {
        change[i]=i+1;
    }
    for(int i=0;i<q;i++)
    {
        char from,to;
        scanf(" %c %c",&from,&to);
        for(int j=0;j<26;j++)
        {
            if(change[j]==from-'a'+1)
            {
                change[j]=to-'a'+1;
            }
        }
        
    }
    for(int i=0;i<strlen(s);i++)
    {
        for(int j='a';j<='z';j++)
        {
            if(s[i]==j)
            {
                printf("%c",change[j-'a']-1+'a');
                
            }
        }
    }
    printf("\n");
    return 0;
}