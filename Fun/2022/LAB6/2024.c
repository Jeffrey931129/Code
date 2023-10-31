#include <stdio.h>

int seq[1000],i;
int main()
{
    char ch;
    
    while((ch=getchar())!=10)
    {
        if(ch-'0'>=0&&'9'-ch>=0)
        {
            seq[i]=ch-'0';
            
            i++;
        }
    }
    
    int num=0,prev=seq[0];
    seq[i]=11;
    for(int j=1;j<i+1;j++)
    {
        if(seq[j]==prev)
        {
            num++;
        }
        else
        {
            if (num)
            {
                switch (num+1)
                {
                case 0:
                    printf("Zero");
                    break;
                case 1:
                    printf("One");
                    break;
                case 2:
                    printf("Two");
                    break;
                case 3:
                    printf("Three");
                    break;
                case 4:
                    printf("Four");
                    break;
                case 5:
                    printf("Five");
                    break;
                case 6:
                    printf("Six");
                    break;
                case 7:
                    printf("Seven");
                    break;
                case 8:
                    printf("Eight");
                    break;
                case 9:
                    printf("Nine");
                    break;
                }
                switch (prev)
                {
                case 0:
                    printf("Zero");
                    break;
                case 1:
                    printf("One");
                    break;
                case 2:
                    printf("Two");
                    break;
                case 3:
                    printf("Three");
                    break;
                case 4:
                    printf("Four");
                    break;
                case 5:
                    printf("Five");
                    break;
                case 6:
                    printf("Six");
                    break;
                case 7:
                    printf("Seven");
                    break;
                case 8:
                    printf("Eight");
                    break;
                case 9:
                    printf("Nine");
                    break;
                }
                prev = seq[j]; num=0;
            }
            else
            {
                switch (prev)
                {
                case 0:
                    printf("Zero");
                    break;
                case 1:
                    printf("One");
                    break;
                case 2:
                    printf("Two");
                    break;
                case 3:
                    printf("Three");
                    break;
                case 4:
                    printf("Four");
                    break;
                case 5:
                    printf("Five");
                    break;
                case 6:
                    printf("Six");
                    break;
                case 7:
                    printf("Seven");
                    break;
                case 8:
                    printf("Eight");
                    break;
                case 9:
                    printf("Nine");
                    break;
                }
                prev = seq[j];
            }
        }
    }
    printf("\n");
}