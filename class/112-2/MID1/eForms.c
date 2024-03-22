#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

typedef struct _Node {
    int serial, stu_id;
    char name[1001]; 
    struct _Node* next;
} Node;

void eFormSort(Node *head);
int main() {
    int n;
    Node *head = (Node*)malloc(sizeof(Node));
    Node *node = head;
    Node *rec[5001];
    char status[5001][51];

    scanf("%d", &n);
    scanf("%d%d%s", &node->serial, &node->stu_id, node->name);
    scanf("%s", status[node->serial]);
    rec[node->serial] = node;

    for (int i=2; i<=n; i++) {
        node->next = (Node*)malloc(sizeof(Node));
        node = node->next;
        scanf("%d%d%s", &node->serial, &node->stu_id, node->name);
        scanf("%s", status[node->serial]);
        rec[node->serial] = node;
    }
    node->next = NULL;

    eFormSort(head);

    node = head;
    for (int i=1; i<=n; i++) {
        if (node != rec[i]) {
            printf("Fail...\n");
            return 0;
        }
        printf("%d %d %s %s\n", node->serial, node->stu_id, node->name, status[node->serial]);
        if (i < n) node = node->next;
    }
    return 0;
}

void eFormSort(Node* head)
{
    int stop=0;
    while(!stop)
    {
        Node* temp=head; stop=1;
        if(temp->serial>temp->next->serial)
        {
            Node* a=temp->next;
            temp->next=temp->next->next;
            a->next=temp;
            temp=a;
            stop=0;
        }
        while(temp->next->next!=NULL)
        {
            if(temp->next->serial>temp->next->next->serial)
            {
                Node* a=temp->next->next->next;
                temp->next->next->next=temp->next;
                temp->next=temp->next->next;
                temp->next->next->next=a;
                stop=0;
            }
            temp=temp->next;
        }
    }
}