#include "function.h"

void eFormSort(Node *head) {
    // approch 2: search

    // node: the starting node of linked list to search(unsorted)
    // prev: the tail of sortrd nodes
    Node *node = head, *prev;
    int rec = 1;
    while (node) {
        // a: the previous node of wanted node
        // b: wanted node
        if (node->serial != rec) {
            Node *a = node, *b = node->next;
            while (b->serial != rec) {
                a = a->next;
                b = b->next;
            }
            
            a->next = b->next;  // connect the remaining unsorted nodes
            prev->next = b;     // connect the wanted node to sorted list
                                // because the start of input unsorted list will be 1, "prev" won't be NULL in this line 
            b->next = node;     // connect the unsorted nodes to the tail of sorted nodes
            node = b;
        }
        
        prev = node;
        node = node->next;
        rec++;
    }
}