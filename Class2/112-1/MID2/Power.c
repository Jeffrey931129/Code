#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100001

int cable[N][2], neighborCount[N], *neighbor[N],from[N];
int n,p1,p2,step_max;

void find1(int x,int front,int step)
{
    if(step>step_max)
    {
        p1=x;
        step_max=step;
    }
    for(int i=0;i<neighborCount[x];i++)
    {
        if(neighbor[x][i]!=front)
        {
            find1(neighbor[x][i],x,step+1);
        }
    }
}

void find2(int x,int front,int step)
{
    from[x]=front;
    if(step>step_max)
    {
        p2=x;
        step_max=step;
    }
    for(int i=0;i<neighborCount[x];i++)
    {
        if(neighbor[x][i]!=front)
        {
            find2(neighbor[x][i],x,step+1);
        }
    }
}

void readGraph() {
    scanf("%d", &n);
    for (int i=0; i<n-1; i++) {
        scanf("%d %d", &cable[i][0], &cable[i][1]);
        neighborCount[cable[i][0]]++;
        neighborCount[cable[i][1]]++;
    }
    for (int i=1; i<=n; i++) {
        neighbor[i] = (int*)malloc(neighborCount[i] * sizeof(int));
    }
    int neighborIndex[N] = {};
    for (int i=0; i<n-1; i++) {
        int u = cable[i][0], v = cable[i][1];
        neighbor[u][neighborIndex[u]++] = v;
        neighbor[v][neighborIndex[v]++] = u;
    }
}

int main() {
    readGraph();
    find1(1,0,0);
    step_max=0;
    find2(p1,0,0);
    int answer=p2;
    if(step_max%2)  // 考慮兩個
    {
        for(int i=0;i<step_max/2;i++)
        {
            answer=from[answer];
        }
        answer=fmin(answer,from[answer]);
    }
    else
    {
        for(int i=0;i<step_max/2;i++)
        {
            answer=from[answer];
        }
    }
    // Test the following code
    /*
    for (int i=1; i<=n; i++) {
        int neighborCnt = neighborCount[i];
        printf("%d connects to ", i);
        for (int j=0; j<neighborCnt; j++) {
            printf("%d ", neighbor[i][j]);
        }
        printf("\n");
    }
     */
    printf("%d\n",answer);
    return 0;
}