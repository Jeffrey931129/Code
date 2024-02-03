#include <stdio.h>
#include <math.h>

int main()
{
    int n,min=9999999;
    scanf("%d",&n);
    char direction[n]; int position[n];
    for(int i=0;i<n;i++)
        scanf(" %c",&direction[i]);
    //printf("%s\n",direction);
    for(int i=0;i<n;i++)
        scanf("%d",&position[i]);
    for(int i=0;i<n-1;i++)
    {
        if(direction[i]=='R'&&direction[i+1]=='L')
        {
            min=fmin(min,(position[i+1]-position[i])/2);
        }
    }
    if(min!=9999999) printf("%d\n",min);
    else printf("-1\n");
}