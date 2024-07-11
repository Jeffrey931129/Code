#include <stdio.h>

int n,inorder[200005],tree[200005][3],inorder_pos[200005],root;
int check(int root,int start,int num);
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) tree[i][2]=-1;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d%d",&tree[i][0],&tree[i][1]);
            tree[tree[i][0]][2]=tree[tree[i][1]][2]=i;
        }
        root=1;
        while(tree[root][2]!=-1) root=tree[root][2];
        for(int i=0;i<n;i++) 
        {
            scanf("%d",&inorder[i]);
            inorder_pos[inorder[i]]=i;
        }
        if(check(root,0,n)) printf("YES\n");
        else printf("NO\n");
    }
}

int check(int root,int start,int num)
{
    if(!tree[root][0]&&!tree[root][1])
    {
        if(num!=1) return 0;
        else return 1;
    }
    for(int i=0;i<2;i++)
    {
        if(tree[root][i])
        {
            if(inorder_pos[tree[root][i]]>=start&&inorder_pos[tree[root][i]]<start+num)
            {
                if(inorder_pos[tree[root][i]]>inorder_pos[root])
                {
                    if(!check(tree[root][i],inorder_pos[root]+1,num-inorder_pos[root]+start-1)) return 0;
                }
                else 
                {
                    if(!check(tree[root][i],start,inorder_pos[root]-start)) return 0;
                }
            }
            else return 0;
        }
        else
        {
            if(inorder_pos[root]-start&&num-inorder_pos[root]+start-1) return 0;
        }
    }
    return 1;
}