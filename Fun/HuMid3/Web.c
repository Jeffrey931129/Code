#include <stdio.h>
#include <string.h>

char s[100005],answer[100005];
int count=0;
int main()
{
    while(1)
    {
        fgets(s,100005,stdin);
        if(strncmp(s,"</body>",7)==0) break;
        int lenth=strlen(s);
        for(int i=0;i<lenth;i++)
        {
            if(s[i]=='<')
            {
                if(strncmp(&s[i],"<title>",7)==0)
                {
                    i+=7; int j=0;
                    while(s[i+j]!='<') j++;
                    strncpy(answer,&s[i],j);
                    i=i+j+8;
                }
                else if(strncmp(&s[i],"</a>",4)==0)
                {
                    i+=4; count++;
                }
            }
        }
    }
    
    printf("%s\n%d\n",answer,count);
}