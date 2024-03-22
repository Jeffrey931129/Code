#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _node{
    int code;
    struct _node* left;
    struct _node* right;
}Node;

char str[14000];
int pos;
char table[3005];

Node* makeNode(int num){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->code = num;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* ConstructTree(){
    int num = 0;
    while(isdigit(str[pos]) && pos<strlen(str)){ //will stop at '?' or ':'
        num = num*10 + (str[pos]-'0');
        pos++;
    }
    Node* root = makeNode(num);
    if(str[pos] == '?'){
        pos++; //pass '?'
        root->left = ConstructTree();
        root->right = ConstructTree();
        return root;
    }
    pos++;
    return root;
}

//debug
void TraverseTree(Node* root){
    printf("%d\n", root->code);
    if(root->left) TraverseTree(root->left);
    if(root->right) TraverseTree(root->right);
    return;
}

char EvaluateTree(Node* root){
    if(root->left == NULL && root->right == NULL) return table[root->code-1];

    if(table[root->code-1] == '1') return EvaluateTree(root->left);
    else return EvaluateTree(root->right);
}

int main()
{
    scanf("%s", str);
    pos = 0;
    Node* root = ConstructTree();

    //TraverseTree(root);

    int task;
    scanf("%d", &task);
    while(task--){
        scanf("%s", table);
        printf("%c\n", EvaluateTree(root));
    }
    return 0;
}
