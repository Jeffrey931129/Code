#include <stdio.h>
#include <string.h>

int n;
int s[25];
typedef struct _board{
    int exist;
    int val;
}board;
board place[20];
void sort(){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(s[j-1]>s[j]){
                int temp=s[j-1];
                s[j-1]=s[j];
                s[j]=temp;
            }
            else break;
        }
    }
}
void dfs_even(int num){
    if(num==n){
        for(int i=0;i<n;i++) printf("%d ",place[i].val); puts("");
        for(int i=0;i<n;i++) printf("%d ",place[n-i-1].val); puts("");
    }
    for(int i=0;i<n/2;i++){
        if(!place[i*2].exist){
            place[i*2].exist=1,place[i*2].val=s[num];
            dfs_even(num+1);
            place[i*2].exist=0;
        }
        else if(s[num]>place[i*2].val){
            place[i*2+1].exist=1,place[i*2+1].val=s[num];
            dfs_even(num+1);
            place[i*2+1].exist=0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&s[i]);
    
    //for(int i=0;i<n;i++) printf("%d ",s[i]); printf("\n");
    if(n==1){
        printf("1\n%d\n",s[0]);
    }
    else if(n==2){
        if(s[0]!=s[1]){
            printf("2\n%d %d\n%d %d\n",s[0],s[1],s[1],s[0]);
        }
    }
    else if(n%2){    // 奇數
        sort();
    }
    else{   // 偶數
        sort();
        dfs_even(0);
    }
}