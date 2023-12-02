#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char* string, char* pattern, int* splittedStrings);
void free_(char **result, int splitsplittedStrings_num);

int main(){
    char pattern[10];
    char string[500];
    scanf("%s",string);
    scanf("%s",pattern);
    int splittedStrings = 0;
    char **result = split(string, pattern, &splittedStrings);
    for(int i=0; i<splittedStrings; ++i){
        printf("%s\n",result[i]);
    }
    free_(result, splittedStrings);
    return 0;
}

char **split(char* string, char* pattern, int* splittedStrings)
{
    char** s=malloc(500*sizeof(char*));
    for(int i=0;i<500;i++)
    {
        s[i]=malloc(500*sizeof(char));
    }
    int lenth_string=strlen(string),lenth_pattern=strlen(pattern),rec=0;
    
    for(int i=0;i<lenth_string;i++)
    {
        if(string[i]==pattern[0])
        {
            if(strncmp(&string[i],pattern,lenth_pattern)==0)
            {
                int j;
                for(j=i;j<i+lenth_pattern;j++)
                {
                    string[j]=0;
                }
                i=j-1;
                
            }

        }
    }
    for(int i=0;i<lenth_string;)
    {
        if(string[i]!=0)
        {
            strcpy(s[rec],&string[i]);
            
            i+=strlen(s[rec]); rec++; (*splittedStrings)++;
        }
        else if(string[i]==0)
        {
            i+=lenth_pattern; 
        }
    }
    

    return s;
}

void free_(char **result, int splitsplittedStrings_num)
{
    for(int i=0;i<splitsplittedStrings_num;i++)
    {
        free(result[i]);
    }
    free(result);
}