#include <stdio.h>

int main()
{
    char ch;
    int check=0,end=0,final=0,end1=1;
    while(final!=1)
    {
        while((ch=getchar())!=10)
        {
            end=1;
            if(ch!=';')
            {
                check++;
            }
            if(check==0)
            {
                ch=' ';
            }
            if((ch=='{'||ch=='}'))
            {
                end--;
            }
            if(ch=='#')
            {
                end1--;
            }
            if(ch==EOF)
            {
                final++;
                break;
            }
            putchar(ch);
        }
        if(final)
        {
            break;
        }
        //printf("    %d",end);
        if(end==0||end1==0)
        {
            printf("\n");
        }
        else
        {
            printf(";\n");
        }
        end=0;check=0;end1=1;
    }
    
    return 0;
}