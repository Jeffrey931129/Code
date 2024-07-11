#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    char letter;
    struct _Node* next;
    struct _Node* prev;
} Node;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        Node head,back,*temp;
        head.prev=back.next=NULL,head.next=&back,temp=back.prev=&head;
        
        while(n--)
        {
            char c; scanf(" %c",&c);
            if(c=='B')
            {
                Node* a=temp;
                temp->prev->next=temp->next,temp->next->prev=temp->prev;
                temp=temp->prev;
                free(a);
            }
            else if(c=='L')
            {
                temp=temp->prev;
            }
            else if(c=='R')
            {
                temp=temp->next;
            }
            else
            {
                Node* node=malloc(sizeof(Node));
                node->letter=c,node->prev=temp,node->next=temp->next,temp->next=node,node->next->prev=node;
                temp=temp->next;
            }
        }
        temp=(&head);
        while(temp->next->next!=NULL) 
        {
            printf("%c",temp->next->letter);
            temp=temp->next;
        }
        while(temp!=&head)
        {
            Node* a=temp;
            temp=temp->prev;
            free(a);
        }
        puts("");
    }
}