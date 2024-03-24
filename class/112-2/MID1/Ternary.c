#include <stdio.h>
#include <stdbool.h>

typedef struct _variable
{
    int num;
    char oper;
}variable;
variable s[8005];
int i,q,pos,value[3005],find();

int main()
{
    do{
        scanf("%d",&s[i].num);
        i++;
        scanf("%c",&s[i].oper);
    }while(s[i].oper!=10&&i++);
    scanf("%d",&q);
    while(q--)
    {
        for(int j=1;j<=i/2+1;j++) scanf("%1d",&value[j]);
        if(i==1)
        {
            printf("%d\n",value[s[pos].num]); continue;
        }
        pos=0;
        int ans=find();
        printf("%d\n",ans);
    }
}

int find()
{
    if(value[s[pos].num])
    {
        pos+=2;
        if(s[pos+1].oper=='?') return find();
        else return value[s[pos].num];
    }
    else
    {
        pos+=2;
        if(s[pos+1].oper==':') 
        {
            pos+=2;
            if(s[pos+1].oper=='?') return find();
            else return value[s[pos].num];
        }
        else
        {
            int rec=-1;
            while(rec!=1)
            {
                pos+=2;
                if(s[pos+1].oper==':') rec++;
                else rec--;
            }
            pos+=2;
            if(s[pos+1].oper=='?') return find();
            else return value[s[pos].num];
        }
    }
}