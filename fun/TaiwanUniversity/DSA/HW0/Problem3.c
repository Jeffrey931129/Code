#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node{
    int x;
    struct _Node* next;
}node;

void connect(node* temp_a,node* temp_b);
void print(node* arr,int num);

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    node** arr=malloc(sizeof(node*)*n);
    for(int i=0;i<n;i++){
        arr[i]=malloc(sizeof(node));
        arr[i]->x=-1,arr[i]->next=NULL;
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
            }
            else{
                node* temp=arr[stack-1]->next;
                while(temp->next!=NULL) temp=temp->next;
                temp->next=malloc(sizeof(node));
                temp->next->x=num,temp->next->next=NULL;
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
            node *temp_a=arr[a-1]->next,*temp_b=arr[b-1];
            connect(temp_a,temp_b);
            node* temp=malloc(sizeof(node));
            temp->x=arr[a-1]->x,temp->next=arr[b-1];
            arr[b-1]=temp; arr[a-1]->x=-1,arr[a-1]->next=NULL;
        }
    }
    for(int i=0;i<n;i++){
        print(arr[i],1);
        puts("");
    }
}

void connect(node* temp_a,node* temp_b){
    if(temp_a->next!=NULL&&temp_b->next!=NULL) connect(temp_a->next,temp_b->next);
    if(temp_b->next==NULL){
        temp_b->next=temp_a;
    }
    else{
        temp_a->next=temp_b->next;
        temp_b->next=temp_a;
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