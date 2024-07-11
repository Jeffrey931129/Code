#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    int idx;
    struct node* next;
} Node;

void AddFront(Node** head, Node** back, int num);
void AddBack(Node** head, Node** back, int num);
void DeleteFront(Node** head, Node** back);
void Delete(Node** head, Node** back, int num);
void Swap(Node** head, Node** back);

int main()
{
    char str[50];
    
    Node* head = (Node*) malloc(sizeof(Node));
    Node* back = head;
    // initialize the dummy head
    
    // we'll append the element after this dummy head to avoid runtime error.
    head->idx = -1;
    head->next = NULL;
    
    while (scanf("%s", str) != EOF) {
        
        int num;
        
        if (!strcmp(str, "AddFront")) {
            scanf("%d", &num);
            AddFront(&head, &back, num);
            
        }
        else if (!strcmp(str, "AddBack")) {
            scanf("%d", &num);
            AddBack(&head, &back, num);
            
        }
        else if (!strcmp(str, "DeleteFront")) {
            DeleteFront(&head, &back);
            
        }
        else if (!strcmp(str, "Delete")) {
            scanf("%d", &num);
            Delete(&head, &back, num);
            
        }
        else if (!strcmp(str, "Swap")) {
            Swap(&head, &back);
            
        }
        Node* print = head;
        while (print != NULL) {
        printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        print = print->next;
        }
        printf("%d %d\n",head->idx,back->idx);
    }
    
    // print all the element except the dummy head and free them.
    Node* print = head;
         
    if (head->next == NULL) printf("empty\n");
    
    while (print != NULL) {
        if (print->idx != -1)
            printf("%d%c", print->idx, (print->next == NULL ? '\n' : ' '));
        
        Node* del = print;
        print = print->next;
        free(del);
    }
}

void AddFront(Node** head, Node** back, int num)
{
    if((*head)->idx==-1) 
    {
        (*head)->idx=num; return;
    }
    Node* temp=malloc(sizeof(Node));
    temp->next=*head,temp->idx=num;
    *head=temp; return;
}
void AddBack(Node** head, Node** back, int num)
{
    if((*back)->idx==-1) 
    {
        (*back)->idx=num; return;
    }
    Node* temp=malloc(sizeof(Node));
    (*back)->next=temp,temp->idx=num,temp->next=NULL;
    *back=temp; return;
}
void DeleteFront(Node** head, Node** back)
{
    if((*head)->next==NULL)
    {
        (*head)->idx=-1;
    }
    else
    {
        Node* temp=*head;
        *head=(*head)->next; free(temp);
    }
    return;
}
void Delete(Node** head, Node** back, int num)
{
    if((*head)->next==NULL) 
    {
        if((*head)->idx==num) (*head)->idx=-1;
        return;
    } 
    while((*head)->idx==num)
    {
        if(*head==*back)
        {
            (*head)->idx=-1,(*head)->next=NULL;
            return;
        }
        *head=(*head)->next;
    } 
    Node* temp=*head;
    while(1)
    {   
        if(temp->next==NULL) break;
        
        while(temp->next->idx==num)
        {
            if(temp->next->next==NULL) 
            {
                temp->next=NULL; break;
            }
            else temp->next=temp->next->next;
        }
    }
    *back=temp; return;
}
void Swap(Node** head, Node** back)
{
    if((*head)->idx==-1) return;
    static int rec=0;
    Node* temp=*head;
    if((*head)->next!=NULL)
    {
        *head=(*head)->next;
        Swap(head,back); rec++;
    }
    else
    {
        return;
    }
    temp->next->next=*back=temp; rec--;
    if(!rec)
    {
        temp->next=NULL;
    }
    return;
}