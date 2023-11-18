#include <stdio.h>
#include <string.h>
#include <math.h>

int n,k;
char ;
int main()
{
    scanf("%d%d",&n,&k);
    char ch,sub[15],s[n][305];
    int num_seven[n],rank[n],big[k],temp,rec_sub=0,time=n;
    while(time--)
    {
        
        rec_sub=0;
        while((ch=getchar()))
        {
            if(ch=='|')
            {
                sub[rec_sub]='\0'; sscanf(sub,"%x",&temp); sprintf(sub,"%d",temp);
                stract(s[time],sub); rec_sub=0; 
                
            }
            else if(ch==10)
            {
                sub[rec_sub]='\0'; sscanf(sub,"%x",&temp); sprintf(sub,"%d",temp);
                stract(s[time],sub); rec_sub=0; 
                break;
            }
            else
            {
                sub[rec_sub]=ch; rec_sub++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<strlen(s[i]);j++)
        {
            if(s[i][j]==7)
            {
                num_seven[i]++;
            }
        }
    }
}
