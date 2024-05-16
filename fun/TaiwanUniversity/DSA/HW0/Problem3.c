#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node{
    int x;
    struct _Node* next;
    struct _Node* prev;
}node;

int connect(node* temp_a,node* temp_b);
void print(node* head,int num);

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    node** head=malloc(sizeof(node*)*n);
    node** tail=malloc(sizeof(node*)*n);
    for(int i=0;i<n;i++){
        head[i]=malloc(sizeof(node));
        head[i]->x=-1,head[i]->next=NULL,head[i]->prev=NULL;
        tail[i]=head[i];
    }
    for(int i=0;i<m;i++){
        int type; scanf("%d",&type);
        if(type==1){
            int stack,num; scanf("%d%d",&stack,&num);
            stack--;
            if(head[stack]->x==-1) head[stack]->x=num;
            else{
                tail[stack]->next=malloc(sizeof(node));
                tail[stack]->next->x=num,tail[stack]->next->next=NULL;
                tail[stack]->next->prev=tail[stack];
                tail[stack]=tail[stack]->next;
            }
        }
        else if(type==2){
            int stack; scanf("%d",&stack);
            stack--;
            if(head[stack]->next==NULL) head[stack]->x=-1;
            else{
                tail[stack]=tail[stack]->prev;
                free(tail[stack]->next);
                tail[stack]->next=NULL;
            }
        }
        else if(type==3){
            int a,b; scanf("%d%d",&a,&b);
            a--,b--;
            if(head[a]->x==-1) continue;
            if(head[b]->x==-1){
                free(head[b]);
                head[b]=head[a],tail[b]=tail[a];
            }
            else{
                tail[b]->next=head[a]; head[a]->prev=tail[b];
                tail[b]=tail[a];
            }
            head[a]=malloc(sizeof(node));
            head[a]->x=-1,head[a]->next=NULL,head[a]->prev=NULL;
            tail[a]=head[a];
        }
        else{
            int a,b; scanf("%d%d",&a,&b);
            a--,b--;
            if(head[a]->x==-1) continue;
            if(head[b]->x==-1){
                free(head[b]);
                head[b]=head[a],tail[b]=tail[a]; 
                head[a]=malloc(sizeof(node));
                head[a]->x=-1,head[a]->next=NULL,tail[a]->prev=NULL;
                tail[a]=head[a];
                continue;
            }
            if(head[a]->next!=NULL){
                if(connect(tail[a]->prev,tail[b])){
                    head[b]=head[a];
                }
            }
            else{
                tail[b]->next=head[a];
                tail[b]=head[a];
            }
            head[a]=malloc(sizeof(node));
            head[a]->x=-1,head[a]->next=NULL,head[a]->prev=NULL;
            tail[b]=tail[a]; tail[a]=head[a];
        }
    }
    for(int i=0;i<n;i++){
        print(head[i],1);
        puts("");
    }
}

int connect(node* temp_a,node* temp_b){
    temp_b->next=temp_a->next; temp_a->next=temp_b;
    temp_b->next->prev=temp_b; 
    if(temp_a->prev!=NULL&&temp_b->prev!=NULL){
        return connect(temp_a->prev,temp_b->prev);
        temp_b->prev=temp_a;
    }
    else if(temp_b->prev==NULL){
        temp_b->prev=temp_a;
        return 1;
    }
    else if(temp_a->prev==NULL){
        temp_b->prev->next=temp_a; 
        temp_a->prev=temp_b->prev; temp_b->prev=temp_a;
        return 0;
    }
    return 0;
}

void print(node* head,int num){
    if(head->x==-1){
        printf("0 "); return;
    }
    if(head->next==NULL) printf("%d ",num);
    else print(head->next,num+1);
    printf("%d ",head->x);
}