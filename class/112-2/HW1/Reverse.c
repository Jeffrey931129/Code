#include <stdlib.h>
#include <stdio.h>
typedef struct _Node {
    char val;
    struct _Node* next;
} Node;
 
//list[i]'s head node
Node *head[100005] = {};
 
//list[i]'s tail node
Node *tail[100005] = {};
 
//reverse(list[i])'s head node
Node *rev_head[100005] = {};      
 
//reverse(list[i])'s tail node
Node *rev_tail[100005] = {};
 
/*
list[a] = 1 -> 2 -> 3 -> 4
rev_list[a] = 4 -> 3 -> 2 -> 1
head[a]->val = 1, tail[a]->val = 4
rev_head[a]->val = 4, rev_tail[a]->val = 1
you can use rev_head and rev_tail to get O(1) reverse
*/
 
void swap(int a, int b) {
    //swap list[a] and list[b]
    Node *temp = head[a];
    head[a]=head[b]; head[b]=temp;
    temp=tail[a]; tail[a]=tail[b]; tail[b]=temp;
    temp=rev_head[a]; rev_head[a]=rev_head[b]; rev_head[b]=temp;
    temp=rev_tail[a]; rev_tail[a]=rev_tail[b]; rev_tail[b]=temp;
    /* swap(head_node)
    tmp = head[a];
    head[a] = head[b];
    head[b] = tmp;
    */
 
    /* swap(tail_node)
 
    */

    /*swap(rev_head)
 
    */

    /*swap(rev_tail)
 
    */
}
void append(int a, int b) {
    //append list[a] to list[b]'s behind
    if(head[a] == NULL) return;
    if(head[b] == NULL) {
        swap(a, b);
        return;
    }
    /*
    tail[b]->next = head[a];
    tail[b] = ...
    ...
    */
}
void reverse(int a) {
    //reverse list[a]
    if(head[a] == NULL||head[a]->next==NULL) return;
    /*
    use rev_head and rev_tail to reverse list[a] in O(1)
    hint: swap something
    */
    // Node* temp=*head;
    // *head=(*head)->next;
    // reverse(head);
    // temp->next->next=temp;
    Node* temp=head[a]; head[a]=rev_head[a]; rev_head[a]=temp;
    temp=tail[a]; tail[a]=rev_tail[a]; rev_tail[a]=temp;
}

int main()
{
    int n,q; scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a; scanf("%d",&a);
        if(a)
        {
            head[i]=malloc(sizeof(Node)); Node* temp=head[i];
            rev_head[i]=malloc(sizeof(Node)); Node* temp2=rev_head[i];
            char string[a+1]; scanf(" %s",string);
            for(int i=0;i<a;i++)
            {
                temp->val=string[i],temp2->val=string[a-1-i];
                if(i!=a-1)
                {
                    temp->next=malloc(sizeof(Node)); temp=temp->next;
                    temp2->next=malloc(sizeof(Node)); temp2=temp2->next;
                }
                else
                {
                    temp->next=NULL; temp2->next=NULL;
                }
            }
            tail[i]=temp,rev_tail[i]=temp2;
        }
    }

    scanf("%d",&q);
    while(q--)
    {
        int command,a; scanf("%d%d",&command,&a);
        if(command==1)
        {
            int b; scanf("%d",&b); a--,b--;
            if(tail[a]==NULL) continue; if(tail[b]==NULL) tail[b]=tail[a];
            tail[a]->next=head[b]; head[b]=head[a]; head[a]=tail[a]=NULL;

            if(rev_tail[b]==NULL) rev_head[b]=rev_head[a];
            else rev_tail[b]->next=rev_head[a];
            rev_tail[b]=rev_tail[a]; rev_head[a]=rev_tail[a]=NULL;
        }
        else if(command==2)
        {
            int b; scanf("%d",&b); a--,b--; if(tail[a]==NULL) continue;
            if(tail[b]==NULL) head[b]=head[a];
            else tail[b]->next=head[a];
            tail[b]=tail[a]; head[a]=tail[a]=NULL;

            if(rev_tail[a]==NULL) continue; if(rev_tail[b]==NULL) rev_tail[b]=rev_tail[a];
            rev_tail[a]->next=rev_head[b]; rev_head[b]=rev_head[a]; rev_head[a]=rev_tail[a]=NULL;
        }
        else if(command==3)
        {
            int b; scanf("%d",&b);
            swap(a-1,b-1);
        }
        else
        {
            // tail[a-1]=head[a-1];
            // reverse(&head[a-1]);
            // if(tail[a-1]!=NULL) tail[a-1]->next=NULL;
            reverse(a-1);
        }

        // for(int i=0;i<n;i++)
        // {
        //     Node* temp=head[i];
        //     while(temp!=NULL)
        //     {
        //         printf("%c",temp->val);
        //         temp=temp->next;
        //     }
        //     puts("");
        // }
    }

    for(int i=0;i<n;i++)
    {
        while(head[i]!=NULL)
        {
            printf("%c",head[i]->val);
            head[i]=head[i]->next;
        }
        puts("");
    }
}