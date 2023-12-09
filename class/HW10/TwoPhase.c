#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,v[30],compare(const void*,const void*);  // v[alphabet]=0代表最優先
char s[100][10],temp,*rank[100];  
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
        rank[l]=s[l];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(strcmp(s[j-1],s[j])>0)
            {
                char temp[10];
                strcpy(temp,s[j-1]);
                strcpy(s[j-1],s[j]);
                strcpy(s[j],temp);
            }
            else
            {
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%s",s[i]);
        if(i!=n-1) printf(" ");
        else printf("\n");
    }
}

int compare(const void* x,const void* y)
{
    return v[*(const char*)x-'a']-v[*(const char*)y-'a'];
}

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,v[30],compare(const void*,const void*),compare2(const void*,const void*);  // v[alphabet]=0代表最優先
char s[100][10],temp,*rank[100];  
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
        rank[l]=s[l];
    }
    qsort(rank,n,sizeof(char*),compare2);
    for(int i=0;i<n;i++)
    {
        printf("%s",rank[i]);
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
    return strcmp(*(const char**)x,*(const char**)y);
}*/