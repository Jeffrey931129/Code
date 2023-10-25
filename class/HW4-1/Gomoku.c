#include <stdio.h>
#include <string.h>

int main()
{
    int n,HasWon=0,stop=0;
    scanf("%d",&n);
    int array[25][25]={0},input[n+1][2];
    for(int step=1;step<=n;step++)
    {
        scanf("%d %d",&input[step][0],&input[step][1]);
    }
    for(int step=1;step<=n;step++)
    {
        if(step%2==1)
        {
            array[input[step][0]][input[step][1]]=1;
            if(array[input[step][0]][input[step][1]-1]==1||array[input[step][0]][input[step][1]+1]==1)
            {
                for(int x=input[step][0],y=input[step][1]-4;y<=input[step][1];y++)
                {
                    if(array[x][y]==1&&array[x][y+1]==1&&array[x][y+2]==1&&array[x][y+3]==1&&array[x][y+4]==1)
                    {
                        printf("LSC wins at the %dth step.",step);
                        HasWon++;
                        step=n+1;
                        break;
                    }
                }
                if(HasWon)
                {
                    break;
                }
            }
            if(array[input[step][0]-1][input[step][1]]==1||array[input[step][0]+1][input[step][1]]==1)
            {
                for(int x=input[step][0]-4,y=input[step][1];x<=input[step][1];x++)
                {
                    if(array[x][y]==1&&array[x+1][y]==1&&array[x+2][y]==1&&array[x+3][y]==1&&array[x+4][y]==1)
                    {
                        printf("LSC wins at the %dth step.",step);
                        HasWon++;
                        step=n+1;
                        break;
                    }
                }
                if(HasWon)
                {
                    break;
                }
            }
            if(array[input[step][0]-1][input[step][1]-1]==1||array[input[step][0]+1][input[step][1]+1]==1)
            {
                for(int x=input[step][0]-4,y=input[step][1]-4;x<=input[step][1];x++,y++)
                {
                    if(array[x][y]==1&&array[x+1][y+1]==1&&array[x+2][y+2]==1&&array[x+3][y+3]==1&&array[x+4][y+4]==1)
                    {
                        printf("LSC wins at the %dth step.",step);
                        HasWon++;
                        step=n+1;
                        break;
                    }
                }
                if(HasWon)
                {
                    break;
                }
            }    
            if(array[input[step][0]-1][input[step][1]+1]==1||array[input[step][0]+1][input[step][1]-1]==1)
            {
                for(int x=input[step][0]-4,y=input[step][1]+4;x<=input[step][1];x++,y--)
                {
                    if(array[x][y]==1&&array[x+1][y-1]==1&&array[x+2][y-2]==1&&array[x+3][y-3]==1&&array[x+4][y-4]==1)
                    {
                        printf("LSC wins at the %dth step.",step);
                        HasWon++;
                        step=n+1;
                        break;
                    }
                }
                if(HasWon)
                {
                    break;
                }
            }         
        }
            
            
        
        if(step%2==0)   
        {
            array[input[step][0]][input[step][1]]=2;
            if(array[input[step][0]][input[step][1]-1]==2||array[input[step][0]][input[step][1]+1]==2)
            {
                for(int x=input[step][0],y=input[step][1]-4;y<=input[step][1];y++)
                {
                    if(array[x][y]==2&&array[x][y+1]==2&&array[x][y+2]==2&&array[x][y+3]==2&&array[x][y+4]==2)
                    {
                        printf("TSC wins at the %dth step.",step);
                        HasWon++;
                        step=n+1;
                        break;
                    }
                }
                if(HasWon)
                {
                    break;
                }
            }
            if(array[input[step][0]-1][input[step][1]]==2||array[input[step][0]+1][input[step][1]]==2)
            {
                for(int x=input[step][0]-4,y=input[step][1];x<=input[step][1];x++)
                {
                    if(array[x][y]==2&&array[x+1][y]==2&&array[x+2][y]==2&&array[x+3][y]==2&&array[x+4][y]==2)
                    {
                        printf("TSC wins at the %dth step.",step);
                        HasWon++;
                        step=n+1;
                        break;
                    }
                }
                if(HasWon)
                {
                    break;
                }
            }
            if(array[input[step][0]-1][input[step][1]-1]==2||array[input[step][0]+1][input[step][1]+1]==2)
            {
                for(int x=input[step][0]-4,y=input[step][1]-4;x<=input[step][1];x++,y++)
                {
                    if(array[x][y]==2&&array[x+1][y+1]==2&&array[x+2][y+2]==2&&array[x+3][y+3]==2&&array[x+4][y+4]==2)
                    {
                        printf("TSC wins at the %dth step.",step);
                        HasWon++;
                        step=n+1;
                        break;
                    }
                }
                if(HasWon)
                {
                    break;
                }
            }    
            if(array[input[step][0]-1][input[step][1]+1]==2||array[input[step][0]+1][input[step][1]-1]==2)
            {
                for(int x=input[step][0]-4,y=input[step][1]+4;x<=input[step][1];x++,y--)
                {
                    if(array[x][y]==2&&array[x+1][y-1]==2&&array[x+2][y-2]==2&&array[x+3][y-3]==2&&array[x+4][y-4]==2)
                    {
                        printf("TSC wins at the %dth step.",step);
                        HasWon++;
                        step=n+1;
                        break;
                    }
                }
                if(HasWon)
                {
                    break;
                }
                
            }
        }
    }
    if(HasWon==0)
    {
        printf("There's no winner.");
    }
    printf("\n");
    return 0;
}