#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define mod 998244353 // Define a modulo for the beauty calculation.

// Define a node structure for the expression tree.
typedef struct _Node {
    int val; // {0 ~ 9: number, -1: +, -2: -, -3: *}
    int ans;
    struct _Node *lc, *rc; // Left child, right child.
} Node;

char s[505] = {}; // Input string representing the preorder expression of the tree.
int idx = 0; // Index to keep track of the current position in the input string.
int n; // Number of nodes in the tree.
Node *arr[505] = {}; // Array to store pointers to nodes for easy access.

// Function to build the expression tree from the input string.
Node *build() {
    if(idx >= n) return NULL; // Base case: if idx exceeds number of nodes, return NULL.
    Node *r = (Node *)malloc(sizeof(Node)); // Allocate memory for a new node.
    arr[idx] = r; // Store pointer to the new node in arr.
    if(s[idx] >= '0' && s[idx] <= '9'){ // If the current character is a digit:
        r->val = s[idx] - '0'; // Convert character to integer and assign to node's value.
        idx++;
    }
    else { // If the current character is an operator:
        if(s[idx] == '+') r->val = -1; // Assign corresponding value for addition.
        else if(s[idx] == '-') r->val = -2; // Assign corresponding value for subtraction.
        else r->val = -3; // Assign corresponding value for multiplication.
        idx++;
        r->lc = build(); // Recursively build left subtree.
        r->rc = build(); // Recursively build right subtree.
    }
    return r; // Return pointer to the newly created node.
}

// Function to evaluate the expression tree and calculate its beauty.
int eval(Node *r) {
    if(r->val == -1) { // Addition operation.
        return ((1ll * eval(r->lc) + eval(r->rc)) % mod + mod) % mod;
    }
    else if(r->val == -2) { // Subtraction operation.
        return ((1ll * eval(r->lc) - eval(r->rc)) % mod + mod) % mod;
    }
    else if(r->val == -3) { // Multiplication operation.
        return ((1ll * eval(r->lc) * eval(r->rc)) % mod + mod) % mod;
    }
    else { // If the node is a digit.
        return r->val % mod; // Return the value modulo mod.
    }
}

// Utility function to find maximum of two integers.
int max(int a, int b) {
    if(a > b) return a;
    return b;
}

// Depth-First Search function to check if target node is in the subtree rooted at 'now'.
bool dfs(Node *now, Node *target) {
    if(now == NULL) return false; // Base case: reached a leaf node.
    if(now == target) { // If target node is found.
        return true;
    }
    else { // Recursively search in left and right subtrees.
        return dfs(now->lc, target) || dfs(now->rc, target);
    }
}

// Function to check if two nodes have a parent-child relationship.
bool check(int a, int b) {
    // Return false if either is ancestor of the other.
    if(dfs(arr[a], arr[b]) || dfs(arr[b], arr[a])) {
        return false;
    }
    else {
        return true;
    }
}

// Function to swap the subtrees rooted at nodes a and b.
void swap(int a, int b) {
    //swap Node[a] and Node[b]'s left_child
    Node *temp = arr[a]->lc;
    arr[a]->lc = arr[b]->lc;
    arr[b]->lc = temp;

    //swap Node[a] and Node[b]'s right_child
    temp = arr[a]->rc;
    arr[a]->rc = arr[b]->rc;
    arr[b]->rc = temp;

    //swap Node[a] and Node[b]'s value
    int temp2 = arr[a]->val;
    arr[a]->val = arr[b]->val;
    arr[b]->val = temp2;
}

// Main function.
int main() {
    scanf("%d", &n); // Read the number of nodes.
    scanf("%s", s); // Read the preorder expression of the tree.
    Node *root = build(); // Build the expression tree.
    int ans = eval(root); // Calculate initial beauty of the tree.
    // Attempt to swap each pair of nodes and evaluate the new beauty of the tree.
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(check(i, j)) { // Check if the nodes can be swapped.
                swap(i, j); // Perform the swap.
                ans = max(ans, eval(root)); // Update the maximum beauty.
                swap(i, j); // Swap back to original configuration.
            }
        }
    }
    printf("%d\n", ans); // Print the maximum beauty achieved.
}

