#include <stdio.h>
#include <string.h>

char s[10][30000],command[30000],temp[30000];
int main()
{
    
    while(scanf(" %[^\n]",command),strcmp(command,"exit")!=0)
    {
        if(strcmp(command,"print")==0)
        {
            for(int i=0;i<10;i++)
            {
                printf("%d: ",i);
                if(strlen(s[i]))
                {
                    printf("%s\n",s[i]);
                }
                else
                {
                    printf("No card\n");
                }
            }
        }
        else if(strcmp(command,"clear")==0)
        {
            for(int i=0;i<10;i++)
            {
                s[i][0]=0;
            }
        }
        else if(strncmp(command,"all",3)==0)
        {
            int time,rec=4; 
            for(;command[rec]!=' ';rec++)
            sscanf(&command[rec+1],"%d",&time); s[0][0]=0;
            for(int i=0;i<time;i++)
            {
                strncat(s[0],&command[4],rec-4);
                if(i!=time-1)
                {
                    strcat(s[0]," ");
                }
                
            }
            for(int i=1;i<=9;i++)
            {
                strcpy(s[i],s[0]);
            }
        }
        else if(strncmp(command,"place",5)==0)
        {
            scanf(" %[^\n]",temp);
            strcpy(s[command[6]-'0'],temp);  // command是char型態
        }
        else if(strncmp(command,"swap",4)==0)
        {
            if(command[5]==command[7])
            {
                continue;
            }
            else
            {
                strcpy(temp,s[command[5]-'0']);
                strcpy(s[command[5]-'0'],s[command[7]-'0']);
                strcpy(s[command[7]-'0'],temp);
            }
        }
        else if(strncmp(command,"shiftleft",9)==0)
        {
            char rec[30000];
            strcpy(rec,s[0]);
            for(int i=1;i<=9;i++)
            {
                strcpy(s[i-1],s[i]);
            }
            strcpy(s[9],rec);
        }
        else if(strncmp(command,"shiftright",10)==0)
        {
            char rec[30000];
            strcpy(rec,s[9]);
            for(int i=8;i>=0;i--)
            {
                strcpy(s[i+1],s[i]);
            }
            strcpy(s[0],rec);
        }
    }
    return 0;
}