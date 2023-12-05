#include <stdio.h>
#include <string.h>

int n,temp_age,answer_age;
char key[1005],temp[100005],temp_name[100005],rec[5],temp_sentence[100005];

int main()
{
    
    scanf("%d",&n);
    scanf(" %[^\n]",key);
    while(n--)
    {
        scanf(" %[^\n]",temp);
        //printf("%s\n",temp);
        for(int i=0;temp[i]!=0;i++)
        {
            if(temp[i]=='N'&&strncmp(&temp[i],"Name",4)==0)
            {
                int j=0;
                for(;temp[i+j+5]!=';'&&temp[i+j+5]!=0;j++)
                {
                    temp_name[j]=temp[i+j+5];
                }
                temp_name[j]=0;
                i+=j+5;
            }
            else if(temp[i]=='A'&&strncmp(&temp[i],"Age",3)==0)
            {
                int j=0;
                for(;temp[i+j+4]!=';'&&temp[i+j+4]!=0;j++)
                {
                    rec[j]=temp[i+j+4];
                }
                rec[j]=0;
                sscanf(rec,"%d",&temp_age);
                i+=j+4;
                printf("1\n");
            }
            else if(temp[i]=='S'&&strncmp(&temp[i],"Sentence",8)==0)
            {
                int j=0;
                for(;temp[i+j+9]!=';'&&temp[i+j+9]!=0;j++)
                {
                    temp_sentence[j]=temp[i+j+9];
                }
                temp_sentence[j]=0;
                i+=j+9;
            }
        }
        //printf("%d\n%s\n%s\n",temp_age,temp_name,temp_sentence);
        
    }
}