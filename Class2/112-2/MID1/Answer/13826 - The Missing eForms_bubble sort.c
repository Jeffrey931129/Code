#include "function.h"
#include "stdlib.h"

void eFormSort(Node *head) {
    // approch 1: bubble sort

    // count the num of node
    int num = 0;
    Node *ptr = head;
    while(ptr != NULL){
        num++;
        ptr = ptr->next;
    }

    Node *left = NULL;
    Node *right = NULL;
    Node *pre_left = NULL;
    for(int i = num - 1; i >= 1; i--){
        left = head;
        right = head->next;
        for(int j = 1; j <= i; j++){
            if(left == NULL || right == NULL)
                break;

            if(left->serial > right->serial){
                left->next = right->next;
                right->next = left;
                if(left == head){
                    head = right;
                }
                else{
                    pre_left->next = right;
                }

                Node *temp = left;
                left = right;
                right = temp;
            }

            pre_left = left;
            left = right;
            right = right->next;
        }
    }
}