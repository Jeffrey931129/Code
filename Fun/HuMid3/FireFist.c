#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char s[505],key[15];
int lenth_s,lenth_key,vocabulary[505][2],rec;
void compare(int,int);
int main()
{
    scanf("%s",s);
    scanf("%s",key);
    lenth_s=strlen(s),lenth_key=strlen(key);
    
    for(int i=0;i<lenth_s;)
    {
        for(int j=i;j<lenth_s;j++)
        {
            if(s[j]==key[0]&&strncmp(&s[j],key,lenth_key)==0)
            {
                if(i!=j)
                {
                    vocabulary[rec][0]=i,vocabulary[rec][1]=j-1; rec++;
                }
                i=j+lenth_key;
                break;
            }
            else if(j==lenth_s-1)
            {
                vocabulary[rec][0]=i,vocabulary[rec][1]=j; rec++;
                i=j+1; break;
            }
        }
    }
    for(int i=0;i<rec;i++)
    {
        compare(vocabulary[i][0],vocabulary[i][1]);
        
    }
    for(int i=0;i<rec;i++)
    {
        for(int j=vocabulary[i][0];j<=vocabulary[i][1];j++)
        {
            printf("%c",s[j]);
        }
        printf("\n");
    }
}

void compare(int x,int y)
{
    int** record=malloc(sizeof(int*)*62);
    for(int i=0;i<62;i++)
    {
        record[i]=malloc(2*sizeof(int));
    }
    int max_record=0;
    for(int i=0;i<26;i++)
    {
        record[i][0]=i+'A';
        record[i][1]=0;
    }
    for(int i=0;i<26;i++)
    {
        record[i+26][0]=i+'a';
        record[i+26][1]=0;
    }
    for(int i=0;i<10;i++)
    {
        record[i+52][0]=i+'0';
        record[i+52][1]=0;
    }
    for(int i=x;i<=y;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            record[s[i]-'A'][1]++;
            max_record=fmax(max_record,record[s[i]-'A'][1]);
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            record[s[i]-'a'+26][1]++;
            max_record=fmax(max_record,record[s[i]-'a'+26][1]);
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            record[s[i]-'0'+52][1]++;
            max_record=fmax(max_record,record[s[i]-'0'+52][1]);
        }
    }
    int j=x;
    while(max_record)
    {
        for(int i=0;i<62;i++)
        {
            if(record[i][1]==max_record)
            {
                for(int k=0;k<max_record;k++)
                {
                    s[j]=record[i][0];
                    j++;
                }
            }
        }
        max_record--;
    }
    for(int i=0;i<62;i++)
    {
        free(record[i]);
    }
    free(record);
    return;
}