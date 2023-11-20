#include <stdio.h>

void snakemove();
int dir,n,m,s,sx,sy,rx,ry,check();  // 0是向右
int main()
{
    
    scanf("%d%d%d",&n,&m,&s);
    int road[n][m],rank[n*m][2],is_used[n][m];  // 嘗試不做歸0
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&road[i][j]);
            rank[i*m+j][0]=i,rank[i*m+j][1]=j;
            for(int k=i*m+j;k>0;k--)
            {
                if(road[rank[k][0]][rank[k][1]]<road[rank[k-1][0]][rank[k-1][1]])
                {
                    int temp=rank[k][0];
                    rank[k][0]=rank[k-1][0],rank[k-1][0]=temp;
                    temp=rank[k][1];
                    rank[k][1]=rank[k-1][1],rank[k-1][1]=temp;
                }
                else
                {
                    break;
                }
            }
        }
    }
    sx=rank[0][0],sy=rank[0][1],rx=rank[n*m-1][0],ry=rank[n*m-1][1];
    while(s)
    {
        is_used[rx][ry]=1;
        if(sx==rx||sy==ry||ry-sy==rx-sx||ry-sy==sx-rx)  // 探測燈
        {
            if(sy>ry&&sx==rx)  // 向右
            {
                int locx=sx,locy=sy;
                while(rx!=locx||ry!=locy)
                {
                    ry++,s--;
                    snakemove();
                    if(check())
                    {
                        return 0;
                    }
                    is_used[rx][ry]=1;
                }
            }
            else if(sy<ry&&sx==rx)  // 向左
            {
                int locx=sx,locy=sy;
                while(rx!=locx||ry!=locy)
                {
                    ry--,s--;
                    snakemove();
                    if(check())
                    {
                        return 0;
                    }
                    is_used[rx][ry]=1;
                }
            }
            else if(sy==ry&&sx<rx)  // 向上
            {
                int locx=sx,locy=sy;
                while(rx!=locx||ry!=locy)
                {
                    rx--,s--;
                    snakemove();
                    if(check())
                    {
                        return 0;
                    }
                    is_used[rx][ry]=1;
                }
            }
            else if(sy==ry&&sx>rx)  // 向下
            {
                int locx=sx,locy=sy;
                while(rx!=locx||ry!=locy)
                {
                    rx++,s--;
                    snakemove();
                    if(check())
                    {
                        return 0;
                    }
                    is_used[rx][ry]=1;
                }
            }
            else if(sy<ry&&sx>rx)  // 向左下
            {
                int locx=sx,locy=sy;
                while(rx!=locx||ry!=locy)
                {
                    rx++,ry--,s--;
                    snakemove();
                    if(check())
                    {
                        return 0;
                    }
                    is_used[rx][ry]=1;
                }
            }
            else if(sy>ry&&sx>rx)  // 向右下
            {
                int locx=sx,locy=sy;
                while(rx!=locx||ry!=locy)
                {
                    rx++,ry++,s--;
                    snakemove();
                    if(check())
                    {
                        return 0;
                    }
                    is_used[rx][ry]=1;
                }
            }
            else if(sy>ry&&sx<rx)  // 向右上
            {
                int locx=sx,locy=sy;
                while(rx!=locx||ry!=locy)
                {
                    rx--,ry++,s--;
                    snakemove();
                    if(check())
                    {
                        return 0;
                    }
                    is_used[rx][ry]=1;
                }
            }
            else if(sy<ry&&sx<rx)  // 向左上
            {
                int locx=sx,locy=sy;
                while(rx!=locx||ry!=locy)
                {
                    rx--,ry--,s--;
                    snakemove();
                    if(check())
                    {
                        return 0;
                    }
                    is_used[rx][ry]=1;
                }
            }
        }
        else  // teleport
        {
            int k=0,big=1000000000,small=-1000000000,l,o;
            for(;;k++)
            {
                if(rank[k][0]==rx&&rank[k][1]==ry)
                {
                    break;
                }
            }
            for(l=k+1;l<n*m;l++)
            {
                if(!is_used[rank[l][0]][rank[l][1]])
                {
                    big=road[rank[l][0]][rank[l][1]]; break;
                }
            }
            for(o=k-1;o>=0;o--)
            {
                if(!is_used[rank[o][0]][rank[o][1]])
                {
                    small=road[rank[o][0]][rank[o][1]]; break;
                }
            }
            if(big-road[rx][ry]<road[rx][ry]-small)
            {
                rx=rank[l][0],ry=rank[l][1];
            }
            else
            {
                rx=rank[o][0],ry=rank[o][1];
            }
            s--;snakemove();
            //printf("%d\n",road[rx][ry]);
            if(check())
            {
                return 0;
            }
        }
    }
}

void snakemove()
{
    if(sy==0)
    {
        sy++,dir=0;
    }
    else if(sy==m-1)
    {
        sy--,dir=1;
    }
    else
    {
        if(dir==0)
        {
            sy++;
        }
        else
        {
            sy--;
        }
    }
}

int check()
{
    if(sx==rx&&sy==ry)
    {
        printf("%d\nGotcha!\n",s);
        return 1;
    }
    else if(!s)
    {
        printf("%d\nNO Snake QQ~\n",s);
        return 1;
    }
    return 0;
}