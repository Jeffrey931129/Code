#include <stdio.h>
#include <limits.h>
char str[1001];
int delete_map[1001][1001];

int check_palindrome(int l , int r) {
    int delete_left, delete_right;
    if(l>=r) {
        delete_map[l][r] = 0;
        return  delete_map[l][r];
    }
    if(str[l]==str[r]) {
        delete_map[l][r] = check_palindrome( l+1, r-1);
        return delete_map[l][r];
    }
    else {
        if(delete_map[l][r]==INT_MAX) {
            delete_left  = check_palindrome( l+1,   r);
            delete_right = check_palindrome(   l, r-1);
            delete_map[l][r] = (delete_left>delete_right)? delete_right+1: delete_left+1;// choose smaller one
            return delete_map[l][r];
        }
        else   return delete_map[l][r];
    }
}
int main() {
    //declare
    int n, k, ans;
    //read
    scanf("%d %d", &n ,&k);
    scanf("%s", str);
    //initialize
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            delete_map[i][j] = INT_MAX;

    ans = check_palindrome( 0, n-1);
    if(ans<=k)  printf("Yes\n");
    else        printf("No\n");

    return 0;
}
