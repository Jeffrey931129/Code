#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct test
{
    char* arr;
} Point;

Point rank[100];
int n,v[30],compare(const void*,const void*),compare2(const void*,const void*);  // v[alphabet]=0代表最優先
char s[100][10],temp;  
int main()
{
    scanf("%d",&n);
    for(int i=0;i<26;i++)
    {
        scanf(" %c",&temp);
        v[temp-'a']=i;
    }
    for(int l=0;l<n;l++)
    {
        scanf(" %s",s[l]);
        qsort(s[l],6,sizeof(char),compare);
        rank[l].arr=s[l];
    }
    //printf("%d\n",strcmp(rank[0].arr,rank[1].arr));
    qsort(rank,n,sizeof(Point),compare2);
    for(int i=0;i<n;i++)
    {
        printf("%s",rank[i].arr);
        if(i!=n-1) printf(" ");
        else printf("\n");
    }
}

int compare(const void* x,const void* y)
{
    return v[*(const char*)x-'a']-v[*(const char*)y-'a'];
}

int compare2(const void* x,const void* y)
{
    return strcmp(((const Point*)x)->arr,((const Point*)y)->arr);
}