#include <stdio.h>
#include <stdlib.h>

void solve_preorder(int pos,int num,int pos_inorder);
int inorder[200005],preorder[200005];
int main()
{
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&inorder[i]);
    for(int i=0;i<n;i++) scanf("%d",&preorder[i]);
    solve_preorder(0,n,0);
    puts("");
}

void solve_preorder(int pos,int num,int pos_inorder)
{
    int left_num=0;
    while(inorder[pos_inorder+left_num]!=preorder[pos]) left_num++;
    if(left_num>1) solve_preorder(pos+1,left_num,pos_inorder);
    else if(left_num==1) 
    {
        printf("%d ",preorder[pos+1]);
    }
    int right_num=num-1-left_num;
    if(right_num>1) solve_preorder(pos+1+left_num,right_num,pos_inorder+left_num+1);
    else if(right_num==1) 
    {
        printf("%d ",preorder[pos+1+left_num]);
    }
    printf("%d ",preorder[pos]);
}