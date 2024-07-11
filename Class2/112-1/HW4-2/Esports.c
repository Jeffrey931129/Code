#include <stdio.h>

int main()
{
    int N,M,big=pow(10,9);
    scanf("%d%d",&N,&M);
    int sequen[2*N];   // 擴成2*N試試，反正最後print出來就好
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",&sequen[2*i+1]);
    }
    for(int i=0;i<N;i++)
    {
        sequen[2*i]=sequen[2*i+1]/big;
        sequen[2*i+1]%=big;   // 可能為負
        
    }
    
    for(int m=1;m<=M;m++)
    {
        int L,R,X;
        scanf("%d%d%d",&L,&R,&X);
        
        for(int position=2*L-1;position<=2*R-1;position=position+2)
        {
            sequen[position]+=(X%big);
            sequen[position-1]+=(X/big);
            sequen[position-1]+=sequen[position]/big;
            sequen[position]%=big;
        }
    }

    //printf("%d%d\n",sequen[0],sequen[1]);

    for(int i=0;i<(N);i++)
    {
        if(sequen[2*i]==0)
        {
            printf("%d",sequen[2*i+1]);
        }
        else if(sequen[2*i]>0)
        {
            if(sequen[2*i+1]<0)
            {
                sequen[2*i]--;sequen[2*i+1]+=big;
                if(sequen[2*i]==0)
                {
                    printf("%d",sequen[2*i+1]);
                }
                else
                {
                    printf("%d%09d",sequen[2*i],sequen[2*i+1]);
                }
            }
            else
            {
                printf("%d%09d",sequen[2*i],sequen[2*i+1]);
            }
        }
        else
        {
            if(sequen[2*i+1]>0)
            {
                sequen[2*i]++;sequen[2*i+1]-=big;
                if(sequen[2*i]==0)
                {
                    printf("%d",sequen[2*i+1]);
                }
                else
                {
                    printf("%d%09d",sequen[2*i],sequen[2*i+1]*-1);
                }
            }
            else
            {
                printf("%d%09d",sequen[2*i],sequen[2*i+1]*-1);
            }
        }
        if(i!=N-1)
        {
            printf(" ");
        }
    }
    
    printf("\n");
    return 0;
}