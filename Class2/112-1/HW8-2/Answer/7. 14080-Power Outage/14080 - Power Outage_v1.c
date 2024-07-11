#include <stdio.h>
#include <stdlib.h>
#define N 100001
#define MAX(a,b) (((a)>(b))?(a):(b))

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

int dfs(int location, int from) {
    int saSize = 1; // include itself
    for (int i=0; i<neighborCount[location]; i++) {
        int x = neighbor[location][i];
        if (x == from) continue;
        saSize += dfs(x, location);
    }
    return saSize;
}

int main() {
    readGraph();
    int ansArea = 1e9, ansLocation = -1;
	for (int sub=1; sub<=n; sub++) {
    	int maxArea = 0;
    	for (int i=0; i<neighborCount[sub]; i++) {
    	    int x = neighbor[sub][i];
    	    maxArea = MAX(maxArea, dfs(x, sub));
    	}
    	if (maxArea < ansArea) {
    	    ansArea = maxArea;
    	    ansLocation = sub;
    	}
	}
	printf("%d\n", ansLocation);
    return 0;
}