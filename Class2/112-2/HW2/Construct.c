#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int id;
    struct _Node *left,*right;
}Node;
Node* solve_preorder(int pos,int num,int pos_inorder);
void printftree(Node* root);
int inorder[200005],preorder[200005];
int main()
{
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&inorder[i]);
    for(int i=0;i<n;i++) scanf("%d",&preorder[i]);
    Node* root=solve_preorder(0,n,0);
    printftree(root);
    puts("");
}

Node* solve_preorder(int pos,int num,int pos_inorder)
{
    Node* root=malloc(sizeof(Node));
    root->id=preorder[pos];
    int left_num=0;
    while(inorder[pos_inorder+left_num]!=root->id) left_num++;
    if(left_num>1) root->left=solve_preorder(pos+1,left_num,pos_inorder);
    else if(left_num==1) 
    {
        root->left=malloc(sizeof(Node));
        root->left->id=preorder[pos+1],root->left->left=root->left->right=NULL;
    }
    else root->left=NULL;
    int right_num=num-1-left_num;
    if(right_num>1) root->right=solve_preorder(pos+1+left_num,right_num,pos_inorder+left_num+1);
    else if(right_num==1) 
    {
        root->right=malloc(sizeof(Node));
        root->right->id=preorder[pos+1+left_num],root->right->left=root->right->right=NULL;
    }
    else root->right=NULL;
    return root;
}

void printftree(Node* root)
{
    if(root->left==root->right)
    {
        printf("%d ",root->id);
        return;
    }
    if(root->left!=NULL) printftree(root->left);
    if(root->right!=NULL) printftree(root->right);
    printf("%d ",root->id);
}