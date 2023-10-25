#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int array[n][2*n-1],y=2*n-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<y;j++)
        {
            array[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
		array[i-1][(2*n-1)/2]=i;
        for(int j=1;i-j>0;j++)
        {
			array[i-1][y/2+j]=i-j;
            array[i-1][y/2-j]=i-j;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(array[i][j]==0)
            {
                printf(" ");
            }
            else
            {
                printf("%d",array[i][j]);
            }
        }
        printf("\n");
    }
}