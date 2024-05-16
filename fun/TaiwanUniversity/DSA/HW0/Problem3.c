#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node{
    int x;
    struct _Node* next;
    struct _Node* prev;
}node;

int connect(node* temp_a,node* temp_b);
void print(node* arr,int num);

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    node** arr=malloc(sizeof(node*)*n);
    for(int i=0;i<n;i++){
        arr[i]=malloc(sizeof(node));
        arr[i]->x=-1,arr[i]->next=NULL,arr[i]->prev=NULL;
    }
    for(int i=0;i<m;i++){
        int type; scanf("%d",&type);
        if(type==1){
            int stack,num; scanf("%d%d",&stack,&num);
            if(arr[stack-1]->x==-1) arr[stack-1]->x=num;
            else if(arr[stack-1]->next==NULL){
                arr[stack-1]->next=malloc(sizeof(node));
                arr[stack-1]->next->x=num;
                arr[stack-1]->next->next=NULL;
                arr[stack-1]->next->prev=arr[stack-1];
            }
            else{
                node* temp=arr[stack-1]->next;
                while(temp->next!=NULL) temp=temp->next;
                temp->next=malloc(sizeof(node));
                temp->next->x=num,temp->next->next=NULL;
                temp->next->prev=temp;
            }
        }
        else if(type==2){
            int stack; scanf("%d",&stack);
            if(arr[stack-1]->next==NULL) arr[stack-1]->x=-1;
            else{
                node* temp=arr[stack-1];
                while(temp->next->next!=NULL) temp=temp->next;
                free(temp->next);
                temp->next=NULL;
            }
        }
        else if(type==3){
            int a,b; scanf("%d%d",&a,&b);
            if(arr[a-1]->x==-1) continue;
            if(arr[b-1]->x==-1){
                arr[b-1]->x=arr[a-1]->x,arr[b-1]->next=arr[a-1]->next;
            }
            else{
                node* temp=arr[b-1]->next;
                while(temp->next!=NULL) temp=temp->next;
                temp->next=malloc(sizeof(node));
                temp->next->x=arr[a-1]->x,temp->next->next=arr[a-1]->next;
                temp->next->prev=temp; arr[a-1]->next->prev=temp->next;
            }
            arr[a-1]->x=-1,arr[a-1]->next=NULL;
        }
        else{
            int a,b; scanf("%d%d",&a,&b);
            if(arr[a-1]->x==-1) continue;
            if(arr[b-1]->x==-1){
                arr[b-1]->x=arr[a-1]->x,arr[b-1]->next=arr[a-1]->next;
                arr[a-1]->x=-1,arr[a-1]->next=NULL; continue;
            }
            node *temp_a=arr[a-1],*temp_b=arr[b-1];
            if(arr[a-1]->next!=NULL){
                while(temp_a->next->next!=NULL) temp_a=temp_a->next;
                while(temp_b->next!=NULL) temp_b=temp_b->next;
                if(connect(temp_a,temp_b)){
                    arr[b-1]=arr[a-1];
                }
            }
            arr[a-1]=malloc(sizeof(node));
            arr[a-1]->x=-1,arr[a-1]->next=NULL;
        }
    }
    for(int i=0;i<n;i++){
        print(arr[i],1);
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
    else if(temp_a->prev==NULL){
        temp_b->prev->next=temp_a; 
        temp_a->prev=temp_b->prev; temp_b->prev=temp_a;
        return 0;
    }
    else if(temp_b->prev==NULL){
        temp_b->prev=temp_a;
        return 1;
    }
}

void print(node* arr,int num){
    if(arr->x==-1){
        printf("0 "); return;
    }
    if(arr->next==NULL) printf("%d ",num);
    else print(arr->next,num+1);
    printf("%d ",arr->x);
}