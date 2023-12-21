#include <stdio.h>

int find[10000][2];
int main()
{
    int r,c,t,i=0;
    scanf("%d%d%d",&r,&c,&t);
    char cl[r][c+1];
    for(int x=0;x<r;x++)
    {
        scanf("%s",cl[x]);
        for(int y=0;y<c;y++)
        {
            
            if(cl[x][y]=='F')
            {
                find[i][0]=x;
                find[i][1]=y;
                i++;
            }
        }
    }
    
    int j=0;
    while(t--)
    {
        
        for(int k=i;j<k;j++)
        {
            if(cl[find[j][0]-1][find[j][1]]=='C')
            {
                cl[find[j][0]-1][find[j][1]]='F';
                find[i][0]=find[j][0]-1;
                find[i][1]=find[j][1];
                i++;
            }
            if(cl[find[j][0]+1][find[j][1]]=='C')
            {
                cl[find[j][0]+1][find[j][1]]='F';
                find[i][0]=find[j][0]+1;
                find[i][1]=find[j][1];
                i++;
            }
            if(cl[find[j][0]][find[j][1]-1]=='C')
            {
                cl[find[j][0]][find[j][1]-1]='F';
                find[i][0]=find[j][0];
                find[i][1]=find[j][1]-1;
                i++;
            }
            if(cl[find[j][0]][find[j][1]+1]=='C')
            {
                cl[find[j][0]][find[j][1]+1]='F';
                find[i][0]=find[j][0];
                find[i][1]=find[j][1]+1;
                i++;
            }
        }
    }
    for(int x=0;x<r;x++)
    {
        for(int y=0;y<c;y++)
        {
            printf("%c",cl[x][y]);
        }
        printf("\n");
    }

}