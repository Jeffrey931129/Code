#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int N,x=0,y=-1;
        scanf("%d",&N);
        char spiral[N][N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                spiral[i][j]=' ';
            }
            
        }
        for(int j=0;N-j>0;j++)
        {
            for(int k=1;k<=N-j;k++)
            {
                switch(j%4)
                {
                    case 0:y++;spiral[x][y]='#';break;
                    case 1:x++;spiral[x][y]='#';break;
                    case 2:y--;spiral[x][y]='#';break;
                    case 3:x--;spiral[x][y]='#';break;
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(spiral[i][j]!='#')
                {
                    printf(" ");
                }
                else
                {
                    printf("%c",spiral[i][j]);
                }
                
            }
            printf("\n");
        }
    }
    return 0;
}