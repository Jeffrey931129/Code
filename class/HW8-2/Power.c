#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100001

int cable[N][2], neighborCount[N], *neighbor[N],find(int,int),answer[N];
int n;

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
    find(1,0);
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
    int finalanswer=1;
    for(int i=1;i<=n;i++)
    {
        finalanswer=answer[i]<answer[finalanswer]?i:finalanswer;
    }
    printf("%d\n",finalanswer);
    return 0;
}

int find(int x,int front)
{
    if(neighborCount[x]==1&&x!=1)
    {
        answer[x]=n-1;
        return 1;
    }

    int *arr=malloc(sizeof(int)*(neighborCount[x]-1)),total=0,max=0,rec=0;
    for(int i=0;i<neighborCount[x];i++)
    {
        if(neighbor[x][i]!=front)
        {
            arr[rec]=find(neighbor[x][i],x);
            total+=arr[rec]; max=fmax(max,arr[rec]);
            rec++;
        }
        
    }
    answer[x]=fmax(max,n-total-1);
    free(arr);
    return total+1;
}