#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trans(char*);
int n,answer,rec,lenth_key;
char key[1005],temp_key[1005],len[100005],temp[100005];
int main()
{
    scanf("%d",&n);
    scanf("%s",key);
    lenth_key=strlen(key);
    trans(key);
    while(n--)
    {
        rec=0;
        scanf(" %[^\n]",temp);
        //printf("%s",temp);
        int lenth=strlen(temp);
        for(int i=0;i<lenth;i++)
        {
            int j=i;
            for(;(temp[j]>='a'&&temp[j]<='z')||(temp[j]>='A'&&temp[j]<='Z');j++)
            {
                
            }
            if(j-i==lenth_key)
            {
                strncpy(temp_key,&temp[i],j-i);
                trans(temp_key);
                if(strcmp(temp_key,key)==0)
                {
                    rec++;
                }
            }
            i=j;
        }
        if(rec>answer)
        {
            strcpy(len,temp); answer=rec;
        }
    }
    for(int i=0;len[i]!=0;i++)
    {
        printf("%c",len[i]);
        if(len[i]==':')
        {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}

void trans(char* s)
{
    for(int i=0;s[i]!=0;i++)
    {
        s[i]=toupper(s[i]);
    }
    return;
}