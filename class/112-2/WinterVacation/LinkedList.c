#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data)
{
    if(*nd==NULL||!data) return;
    Node* temp=*nd;
    if(data==1)
    {
        (*nd)=(*nd)->next;
        free(temp);
    }
    else
    {
        int error=0;
        do{
            if(temp->next==NULL)
            {
                error=1; break;
            }
            data--;
        }while(data>1&&(temp=temp->next)); 
        
        if(!error)
        {
            Node* temp2=temp->next;
            temp->next=temp->next->next;
            free(temp2);
        }
    }
}
Node* createList()
{
    Node* head;
    Node* temp;
    int error=0,data;
    scanf("%d",&data);
    if(data>-1){
        head=malloc(sizeof(Node));
        head->data=data,head->next=NULL;
        temp=head;
    }
    else 
    {
        error=1;
    }
    while(!error){
        scanf("%d", &data);
        if(data>-1)
        {
            temp->next=malloc(sizeof(Node));
            temp->next->data=data,temp->next->next=NULL;
            temp=temp->next;
        }
        else break;
    }
    if(error) return NULL;
    return head;
}

void printList(Node *head){
    Node *temp;
    for(temp = head; temp!=NULL; temp=temp->next) {
        printf("%d ", temp->data);
    }
}

void freeList(Node *head){
    Node *temp;
    for(temp=head; temp!=NULL; temp=head){
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head;
    int data;

    head = createList();

    while(1){
        scanf("%d", &data);
        if(data>-1){
            deleteNode(&head,data);
        }else break;

    }

    printList(head);
    freeList(head);
    return 0;
}
