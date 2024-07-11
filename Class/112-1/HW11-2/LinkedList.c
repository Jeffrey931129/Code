#include<stdio.h>
#include<string.h>
#include"function.h"

void Print_List(Node* head);
void Delete_List(Node* head);

int main(){
    char op[10];
    Node* head = NULL;
    while( ~scanf("%s", op) ){
        if( strcmp(op, "push") == 0 ){
            int x;
            scanf("%d", &x);
            Push(&head, x);
        }
        if( strcmp(op, "pop") == 0 ){
            Pop(&head);
        }
        if( strcmp(op, "reverse") == 0 ){
            Reverse_List(&head);
        }
        if( strcmp(op, "print") == 0 ){
            Print_List(head);
        }
    }

    Delete_List(head);
    head = NULL;

    return 0;
}
void Print_List(Node* head){
    if( head == NULL ){
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if( head->next != NULL ) printf(" -> ");
    Print_List(head->next);
}

void Delete_List(Node* head){
    if( head == NULL ) return;
    Delete_List(head->next);
    free(head);
}

void Push(Node** ptr_head, int x)
{
    Node* temp=malloc(sizeof(Node));
    temp->data=x;
    temp->next=*ptr_head;
    *ptr_head=temp; return;
}

void Pop(Node** ptr_head)
{
    if(*ptr_head==NULL) return;
    Node* temp=(*ptr_head)->next;
    free(*ptr_head);
    if(temp==NULL) *ptr_head=NULL;
    else *ptr_head=temp;
    return;
}

void Reverse_List(Node** ptr_head)
{
    if(*ptr_head==NULL) return;
    static int rec=0;
    Node* temp=*ptr_head;
    if((*ptr_head)->next!=NULL)
    {
        *ptr_head=(*ptr_head)->next;
        Reverse_List(ptr_head); rec++;
    }
    else
    {
        return;
    }
    temp->next->next=temp; rec--;
    if(!rec)
    {
        temp->next=NULL;
    }
    return;
}