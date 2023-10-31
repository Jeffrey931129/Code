#include <stdio.h>

int temx,temy,meat_position[100][2],step_num[100],prev_step[250000][2],answer=0,step(int,int,int,int);
char maze[500][500+1];
int main()
{
    int x,y,rec=0;
    scanf("%d%d",&x,&y);
    
    for(int i=0;i<x;i++)
    {
        scanf("%s",maze[i]);
        for(int j=0;i<y;j++)
        {
            if(maze[i][j]=='S')
            {
                temx=i; temy=j;
            }
            if(maze[i][j]=='M')
            {
                meat_position[rec][0]=i; meat_position[rec][1]=j;
                rec++;  // rec=3代表 3 meat
            }
        }
    }
    for(int i=0;i<rec;i++)
    {
        answer+=step_num[i];
    }
    printf("%d\n",answer);
}

int step(int i,int step_num,int x,int y)  // i為第幾片肉
{
    prev_step[step_num][0]=x; prev_step[step_num][1]=y;
    if(maze[prev_step[step_num][0]][prev_step[step_num][1]]=='#'||maze[prev_step[step_num][0]][prev_step[step_num][1]]==maze[prev_step[step_num-2][0]][prev_step[step_num-2][1]])
    {
        return;
    }
    if()
    {

    }

}