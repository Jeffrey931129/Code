#include <stdio.h>
#include <string.h>
#define MAX_SIZE 500

char content[MAX_SIZE];
char input[MAX_SIZE],temp[MAX_SIZE];

int main()
{
    int input_now=0,content_now=0;
    fgets(input, MAX_SIZE, stdin);
    int lenth=strlen(input);
    /* your code here */
    for(int i=0;i<lenth;i++)
    {
        if(input[i]=='/')
        {
            i++;
            if(input[i]=='b')
            {
                i+=8; 
                if(content_now>0)
                {
                    strcpy(&content[content_now-1],&content[content_now]);
                    content_now--;
                }
            }
            else if(input[i]=='n')
            {
                i+=6; 
                strcpy(temp,&content[content_now]);
                content[content_now++]=10;
                strcpy(&content[content_now],temp);
            }
            else if(input[i]=='l')
            {
                i+=3; if(content_now>0) content_now--;
            }
            else if(input[i]=='r')
            {
                i+=4; if(content[content_now]!=0) content_now++;
            }
        }
        else if(input[i]==10)
        {
            continue;
        }
        else
        {
            strcpy(temp,&content[content_now]);
            content[content_now++]=input[i];
            strcpy(&content[content_now],temp);
        }
    }
    int lenth2=strlen(content);
    printf("%s",content);

    return 0;
}