#include <stdio.h>


int a[4],valid(),count(int f,int g,int h,int j,int opp1,int opp2,int opp3);
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        
        scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
        if(valid())
        {
            printf("Safe\n");
        }
        else
        {
            printf("Disqualified\n");
        }
    }
}

int valid()
{
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            int is_used[4]={0},num1,num2;
            is_used[i]=1,is_used[j]=1;
            for(int k=0;k<4;k++)
            {
                if(is_used[k]==0)
                {
                    num1=k; break;
                }
            }
            for(int k=num1+1;k<4;k++)
            {
                if(is_used[k]==0)
                {
                    num2=k; break;
                }
            }
            for(int k=1;k<7;k++)
            {
                for(int l=1;l<7;l++)
                {
                    for(int o=1;o<7;o++)
                    {
                        if(count(a[i],a[j],a[num1],a[num2],k,l,o))
                        {
                            return 1;
                        }  
                    }
                }
            }
            
        }
    }
    return 0;
}

int count(int f,int g,int h,int j,int opp1,int opp2,int opp3)
{
    int temp1=0,temp2=0;
    switch(opp1)
    {
        case 1:
        temp1=f+g; break;
        case 2:
        temp1=f-g; break;
        case 3:
        temp1=f*g; break;
        case 4:
        temp1=f/g; break;
        case 5:
        temp1=g-f; break;
        case 6:
        temp1=g/f; break;
    }
    switch(opp2)
    {
        case 1:
        temp1+=h; break;
        case 2:
        temp1-=h; break;
        case 3:
        temp1*=h; break;
        case 4:
        temp1/=h; break;
        case 5:
        temp1=h-temp1; break;
        case 6:
        temp1=h/temp1; break;
    }
    switch(opp3)
    {
        case 1:
        temp1+=j; break;
        case 2:
        temp1-=j; break;
        case 3:
        temp1*=j; break;
        case 4:
        temp1/=j; break;
        case 5:
        temp1=j-temp1; break;
        case 6:
        temp1=j/temp1; break;
    }
    if(temp1==24)
    {
        return 1;
    }
    
    switch(opp1)
    {
        case 1:
        temp1=f+g; break;
        case 2:
        temp1=f-g; break;
        case 3:
        temp1=f*g; break;
        case 4:
        temp1=f/g; break;
        case 5:
        temp1=g-f; break;
        case 6:
        temp1=g/f; break;
    }
    switch(opp2)
    {
        case 1:
        temp1+=j; break;
        case 2:
        temp1-=j; break;
        case 3:
        temp1*=j; break;
        case 4:
        temp1/=j; break;
        case 5:
        temp1=j-temp1; break;
        case 6:
        temp1=j/temp1; break;
    }
    switch(opp3)
    {
        case 1:
        temp1+=h; break;
        case 2:
        temp1-=h; break;
        case 3:
        temp1*=h; break;
        case 4:
        temp1/=h; break;
        case 5:
        temp1=h-temp1; break;
        case 6:
        temp1=h/temp1; break;
    }
    if(temp1==24)
    {
        return 1;
    }

    switch(opp1)
    {
        case 1:
        temp1=f+g; break;
        case 2:
        temp1=f-g; break;
        case 3:
        temp1=f*g; break;
        case 4:
        temp1=f/g; break;
        case 5:
        temp1=g-f; break;
        case 6:
        temp1=g/f; break;
    }
    switch(opp2)
    {
        case 1:
        temp2=h+j; break;
        case 2:
        temp2=h-j; break;
        case 3:
        temp2=h*j; break;
        case 4:
        temp2=h/j; break;
        case 5:
        temp2=j-h; break;
        case 6:
        temp2=j/h; break;
    }
    switch(opp3)
    {
        case 1:
        temp1+=temp2; break;
        case 2:
        temp1-=temp2; break;
        case 3:
        temp1*=temp2; break;
        case 4:
        temp1/=temp2; break;
        case 5:
        temp1=temp2-temp1; break;
        case 6:
        temp1=temp2/temp1; break;
    }
    if(temp1==24)
    {
        return 1;
    }

    return 0;
}