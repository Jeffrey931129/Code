#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _cat
{
    char* name;
    int identity;
    int age;
}cat;

int compare(const void*,const void*);

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cat cats[n];
        for(int i=0;i<n;i++)
        {
            char temp[20];
            cats[i].name=malloc(35*sizeof(char));
            scanf(" %s %s %d",cats[i].name,temp,&cats[i].age);
            switch(temp[0])
            {
                case 'e':
                cats[i].identity=0; break;
                case 'n':
                cats[i].identity=1; break;
                case 'k':
                cats[i].identity=2; break;
                case 'w':
                cats[i].identity=3; break;
                case 'a':
                cats[i].identity=4; break;
                case 'm':
                cats[i].identity=5; break;
                case 'd':
                cats[i].identity=6; break;
                case 'l':
                cats[i].identity=7; break;
            }
        }
        qsort(cats,n,sizeof(cat),compare);
        for(int i=0;i<m&&i<n;i++)
        {
            printf("%s\n",cats[i].name);
        }
    }
    return 0;
}

int compare(const void* x,const void* y)
{
    cat *a=(cat*)x,*b=(cat*)y;
    if(a->identity==b->identity)
    {
        if(a->age==b->age)
        {
            return strcmp(a->name,b->name);
        }
        if(a->identity==4)
        {
            return a->age-b->age;
        }
        else
        {
            return b->age-a->age;
        }
    }
    else return a->identity-b->identity;
}