#include <stdio.h>
#include <math.h>

int main()
{
    int w,h;
    scanf("%d%d",&w,&h);
    float a[h][w],b[3][3],c[h-2][w-2];
    for(int i=0;i<h-2;i++)
    {
        for(int j=0;j<w-2;j++)
        {
            c[i][j]=0;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%f",&b[i][j]);
        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for(int i=0;i<h-2;i++)
    {
        for(int j=0;j<w-2;j++)
        {
            for(int x=0;x<3;x++)
            {
                for(int y=0;y<3;y++)
                {
                    c[i][j]+=(a[i+x][j+y]*b[x][y]);
                }
            }
            printf("%4d ",(int)(c[i][j]));
        }
        printf("\n");
    }
    
    return 0;
}