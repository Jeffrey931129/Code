#include <stdio.h>
#include <stdlib.h>
#define N 100001

int cable[N][2], neighborCount[N], *neighbor[N];
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
    return 0;
}