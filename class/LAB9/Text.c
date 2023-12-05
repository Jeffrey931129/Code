#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1005

char input[MAX_SIZE];

char command[MAX_SIZE];
int j;

int main()

{

    fgets(input, MAX_SIZE, stdin);

    fgets(command, MAX_SIZE, stdin);

    /* your code here */
    for(int i=0;command[i]!=0;i++)
    {
        if(command[i]=='b')
        {
            if(j>0) 
            {
                strcpy(&input[j-1],&input[j]);
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