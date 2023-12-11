#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n,temp_age,answer_age,answer,j;
char key[1005],temp[100005],temp_name[100005],rec[5],temp_sentence[100005],answer_name[100005],answer_sentence[100005],check[1005];
void trans(char*);
int main()
{
    scanf("%d",&n);
    scanf(" %[^\n]",key);
    int lenth=strlen(key);
    trans(key);
    while(n--)
    {
        //memset(temp,0,100005);  // 為何要加
        scanf(" %[^\n]",temp);
        //printf("%s\n",temp);
        for(int i=0;temp[i]!=0;i++)
        {
            if(temp[i]=='N'&&strncmp(&temp[i],"Name",4)==0)
            {
                j=0;
                for(;temp[i+j+5]!=';'&&temp[i+j+5]!=0;j++)
                {
                    temp_name[j]=temp[i+j+5];
                }
                temp_name[j]=0;
                i+=j+5;
                if(!temp[i]) break;
            }
            else if(temp[i]=='A'&&strncmp(&temp[i],"Age",3)==0)
            {
                j=0;
                for(;temp[i+j+4]!=';'&&temp[i+j+4]!=0;j++)
                {
                    rec[j]=temp[i+j+4];
                }
                rec[j]=0;
                sscanf(rec,"%d",&temp_age);
                i+=j+4;
                if(!temp[i]) break;
                //printf("1\n");
            }
            else if(temp[i]=='S'&&strncmp(&temp[i],"Sentence",8)==0)
            {
                j=0;
                for(;temp[i+j+9]!=';'&&temp[i+j+9]!=0;j++)
                {
                    temp_sentence[j]=temp[i+j+9];
                }
                temp_sentence[j]=0;
                i+=j+9;
                if(!temp[i]) break;
            }
        }
        //printf("%d\n%s\n%s\n",temp_age,temp_name,temp_sentence);
        int count=0;
        for(int i=0;temp_sentence[i]!=0;i++)
        {
            j=i;
            while((temp_sentence[j]>='A'&&temp_sentence[j]<='Z')||(temp_sentence[j]>='a'&&temp_sentence[j]<='z'))
            {
                j++;
            }
            if(j-i==lenth)
            {
                strncpy(check,&temp_sentence[i],j-i);
                trans(check);
                if(strcmp(check,key)==0)
                {
                    count++;
                }
            }
            i=j;
        }
        if(count>answer)
        {
            answer=count;
            answer_age=temp_age;
            strcpy(answer_name,temp_name);
            strcpy(answer_sentence,temp_sentence);
        }
        else if(count==answer&&temp_age>=answer_age)
        {
            answer=count;
            answer_age=temp_age;
            strcpy(answer_name,temp_name);
            strcpy(answer_sentence,temp_sentence);
        }
        
    }
    printf("%s: %s\n",answer_name,answer_sentence);
}

void trans(char* s)
{
    for(int i=0;s[i]!=0;i++)
    {
        s[i]=toupper(s[i]);
    }
    return;
}