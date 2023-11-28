#include <stdio.h>
#include <string.h>
#include <math.h>

int n,k,num_seven[1005];
char ch,s[1005][305];
int main()
{
    scanf("%d %d\n",&n,&k);
    char ch,sub[15];
    int pick[n],big[k],temp,rec_sub=0;
    
    for(int i=0;i<n;i++)
    {
        //printf("%d\n",i);
        rec_sub=0;
        while((ch=getchar())!=EOF)
        {
            if(ch=='|')
            {
                sub[rec_sub]='\0'; sscanf(sub,"%x",&temp); sprintf(sub,"%d",temp);
                strcat(s[i],sub); rec_sub=0; 
                
            }
            else if(ch==10)
            {
                sub[rec_sub]='\0'; sscanf(sub,"%x",&temp); sprintf(sub,"%d",temp);
                strcat(s[i],sub); rec_sub=0; 
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
            if(s[i][j]=='7')
            {
                num_seven[i]++;
            }
        }
        pick[i]=i;
        for(int j=i;j>0;j--)
        {
            if(num_seven[pick[j]]>num_seven[pick[j-1]])
            {
                int temp=pick[j];
                pick[j]=pick[j-1];
                pick[j-1]=temp;
            }
            else if(num_seven[pick[j]]==num_seven[pick[j-1]])
            {
                if(strlen(s[pick[j]])>strlen(s[pick[j-1]]))
                {
                    int temp=pick[j];
                    pick[j]=pick[j-1];
                    pick[j-1]=temp;
                }
                else if(strlen(s[pick[j]])==strlen(s[pick[j-1]]))
                {
                    if(strcmp(s[pick[j]],s[pick[j-1]])>0)
                    {
                        int temp=pick[j];
                        pick[j]=pick[j-1];
                        pick[j-1]=temp;
                    }
                    else
                    {
                        break;
                    }
                    /*int check=0;
                    for(int k=0;k<strlen(s[pick[j]]);k++)
                    {
                        if(s[pick[j]][k]>s[pick[j-1]][k])
                        {
                            int temp=pick[j];
                            pick[j]=pick[j-1];
                            pick[j-1]=temp;
                            break;
                        }
                        else if(s[pick[j]][k]==s[pick[j-1]][k])
                        {
                            continue;
                        }
                        else
                        {
                            check++; break;
                        }
                    }
                    if(check)
                    {
                        break;
                    }*/
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    
    for(int i=0;i<k;i++)
    {
        big[i]=pick[i];
        for(int j=i;j>0;j--)
        {
            if(strlen(s[big[j]])<strlen(s[big[j-1]]))
            {
                int temp=big[j];
                big[j]=big[j-1];
                big[j-1]=temp;
            }
            else if(strlen(s[big[j]])==strlen(s[big[j-1]]))
            {
                if(strcmp(s[big[j]],s[big[j-1]])<0)
                {
                    int temp=big[j];
                    big[j]=big[j-1];
                    big[j-1]=temp;
                }
                else
                {
                    break;
                }
                /*int check=0;
                for(int k=0;k<strlen(s[big[j]]);k++)
                {
                    if(s[big[j]][k]<s[big[j-1]][k])
                    {
                        int temp=big[j];
                        big[j]=big[j-1];
                        big[j-1]=temp;
                        break;
                    }
                    else if(s[big[j]][k]==s[big[j-1]][k])
                    {
                        continue;
                    }
                    else
                    {
                        check++; break;
                    }
                }
                if(check)
                {
                    break;
                }*/
            }
            else
            {
                break;
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        printf("%s\n",s[big[i]]);
    }
    return 0;
}
