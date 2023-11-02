#include <stdio.h>
#include <math.h>

int temx,temy,rec=0,meat_position[250000][2],step_num[250000],prev_step[250000][2],answer=0,direction[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
void step(int,int,int);
char maze[500][500+1];
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    
    for(int i=0;i<x;i++)
    {
        scanf("%s",&maze[i]);
        for(int j=0;j<y;j++)
        {
            
            if(maze[i][j]=='S')
            {
                temx=i; temy=j;
            }
            if(maze[i][j]=='M')
            {
                meat_position[rec][0]=i; meat_position[rec][1]=j;
                rec++;  // rec=3¥Nªí 3 meat
            }
        }
    }
    step(0,temx,temy);
    for(int i=0;i<rec;i++)
    {
        answer+=step_num[i]*2;
    }
    printf("%d\n",answer);
}

void step(int step_now,int x,int y)  
{
    prev_step[step_now][0]=x; prev_step[step_now][1]=y;
    
    if(maze[x][y]=='M')
    {
        for(int i=0;i<rec;i++)
        {
            if(x==meat_position[i][0]&&y==meat_position[i][1])
            {
                if(step_num[i])
                {
                    step_num[i]=fmin(step_num[i],step_now); 
                }
                else
                {
                    step_num[i]=step_now; 
                }
            }
            
        }
    }
    for(int i=0;i<4;i++)
    {
        if(step_now==0)
        {
            if(maze[x+direction[i][0]][y+direction[i][1]]=='#')
            {
                continue;
            }
            else
            {
                step(step_now+1,x+direction[i][0],y+direction[i][1]);
            }
        }
        else
        {
            if(maze[x+direction[i][0]][y+direction[i][1]]=='#'||(x+direction[i][0]==prev_step[step_now-1][0]&&y+direction[i][1]==prev_step[step_now-1][1])||maze[x+direction[i][0]][y+direction[i][1]]=='S')
            {
                continue;
            }
            else
            {
                step(step_now+1,x+direction[i][0],y+direction[i][1]);
            }
        }
        
    }
    return;

}