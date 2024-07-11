#include<iostream>
#include<string.h>
//#include "function.h"
using namespace std;

class ListNode
{
    friend class List_stack; //make List_stack a friend
    public:
        ListNode( const int &info ) //constructor
        : data( info ), nextPtr( NULL ), prevPtr( NULL )
        {
        } //end ListNode constructor

    private:
        int data; //data
        ListNode *nextPtr; // next node in list
        ListNode *prevPtr;
}; //end class ListNode

class List_stack {
    public:
        List_stack();
        ~List_stack();
        void push(const int &);
        void pop();
        void print();
    private:
        ListNode *head;
        ListNode *tail;
};

int main(){
    List_stack L_stack;
    char command[10];
    int n;
    while(cin>>command){

        if(strcmp(command,"pop")==0){
            L_stack.pop();
        }else if(strcmp(command,"push")==0){
            cin >> n;
            L_stack.push(n);
        }else if(strcmp(command, "print") == 0){
            L_stack.print();
            cout << endl;
        }
    }
    return 0;
}

List_stack::List_stack():head(NULL),tail(NULL){}
List_stack::~List_stack(){
    while(head!=NULL){
        ListNode* temp=head;
        head=head->nextPtr;
        delete temp;
    }
}
void List_stack::push(const int& n){
    ListNode* node=new ListNode(n);
    node->nextPtr=head;
    if(head!=NULL) head->prevPtr=node;
    head=node;
    if(tail==NULL) tail=node;
}
void List_stack::pop(){
    if(head!=NULL){
        if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            ListNode* a=head;
            head->nextPtr->prevPtr=NULL;
            head=head->nextPtr;
            delete a;
        }
    }
}
void List_stack::print(){
    ListNode* rec=head;
    int space=0;
    while(rec!=NULL){
        if(space++) cout<<" ";
        cout<<rec->data;
        rec=rec->nextPtr;
    }
}
