#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1005

char input[MAX_SIZE];
char temp[MAX_SIZE];
char command[MAX_SIZE];
int j;

int main()
{
    scanf(" %[^\n]",input);
    scanf(" %[^\n]",command);
    for(int i=0;command[i]!=0;i++)
    {
        if(command[i]=='b')
        {
            if(j>0) 
            {
                strcpy(temp,&input[j]);
                strcpy(&input[j-1],temp);
                j--;
            }
        }
        else if(command[i]=='r')
        {
            if(j<strlen(input))
            {
                j++;
            }
        }
    }
    printf("%s", input);
    return 0;
}