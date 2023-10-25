#include <stdio.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int n,m,answer=1,bigend=0;
        scanf("%d%d",&n,&m);
        int array[n][m];
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                scanf("%d",&array[x][y]);
            }
        }

        for(int x1=0;x1<n;x1++)
        {
            for(int y1=0;y1<m;y1++)
            {
                if((n-x1)*(m-y1)<=answer)
                {
                    break;
                }
                for(int x2=x1;x2<n;x2++)
                {
                    for(int y2=y1;y2<m;y2++)
                    {
                        if((x2-x1+1)*(y2-y1+1)<=answer)
                        {
                            continue;
                        }
                        int end1=0;
                        for(int x=0;x<=x2-x1;x++)
                        {
                            for(int y=0;y<=y2-y1;y++)
                            {
                                if(array[x1+x][y1+y]!=array[x2-x][y2-y])
                                {
                                    end1++;
                                    break;
                                }
                            }
                            if(end1)
                            {
                                break;
                            }
                        }
                        if(end1)
                        {
                            continue;
                        }
                        answer=(x2-x1+1)*(y2-y1+1);
                    }
                }
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}