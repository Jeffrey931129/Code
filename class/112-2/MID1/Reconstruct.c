#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *left,*right;
}Node;
Node* find(int pos,int num);
void printtree(Node* root);
int n,s[100005];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&s[i]);
    Node* root=find(0,n);
    printtree(root);
    puts("");
}

Node* find(int pos,int num)
{
    Node* root=malloc(sizeof(Node));
    root->data=s[pos];
    root->left=root->right=NULL;
    if(num!=1)
    {
        num=(num-1)/2;
        if(s[pos+1]>s[pos+1+num]) root->left=find(pos+1+num,num),root->right=find(pos+1,num);
        else root->right=find(pos+1+num,num),root->left=find(pos+1,num);
    }
    return root;
}

void printtree(Node* root)
{
    static int space=0;
    if(root!=NULL)
    {
        printtree(root->left);
        printtree(root->right);
        if(space++) printf(" ");
        printf("%d",root->data);
    }
}