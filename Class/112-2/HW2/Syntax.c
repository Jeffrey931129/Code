#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "function.h"
#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

#endif

int main(void){
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;
        BTNode *root = EXPR();
        printPrefix(root);
        printf("\n");
        freeTree(root);
    }

    return 0;
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

BTNode* EXPR()
{
    BTNode* node=NULL,*right=NULL;
    if(pos>=0)
    {
        if(expr[pos]>='A'&&expr[pos]<='D') right=makeNode(expr[pos]),pos--;
        else if(expr[pos]==')') pos--,right=EXPR();
    }
    if(expr[pos]=='(')
    {
        node=right,pos--;
        return node;
    }

    if(pos>0)
    {
        node=makeNode(expr[pos]);
        pos--;
        node->left=EXPR();
        node->right=right;
    }
    else node=right;
    return node;
}

BTNode* FACTOR()
{

}
BTNode* makeNode(char c)
{
    BTNode* node=malloc(sizeof(BTNode));
    for(int i=0;i<6;i++)
    {
        if(sym[i]==c)
        {
            node->data=i;
            node->left=node->right=NULL;
            break;
        }
    }
    return node;
}