#include <stdio.h>

int arr[400][400],n,m,lake[80001],rec,size,extend(int,int),clean();
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
            {
                size=0;
                extend(i,j);
                lake[rec]=size;
                clean();
                rec++;
            }
        }
    }
    for(int i=0;i<rec;i++)
    {
        printf("%d\n",lake[i]);
    }
    return 0;
}

int extend(int x,int y)
{
    size++;
    arr[x][y]=0;
    if(arr[x+1][y]==1)
    {
        extend(x+1,y);
    }
    if(arr[x-1][y]==1)
    {
        extend(x-1,y);
    }
    if(arr[x][y+1]==1)
    {
        extend(x,y+1);
    }
    if(arr[x][y-1]==1)
    {
        extend(x,y-1);
    }
    return 0;
}

int clean()
{
    for(int i=rec;i>0;i++)
    {
        if(lake[i]>lake[i-1])
        {
            int temp=lake[i];
            lake[i]=lake[i-1];
            lake[i-1]=temp;
        }
        else
        {
            return 1;
        }
    }
}