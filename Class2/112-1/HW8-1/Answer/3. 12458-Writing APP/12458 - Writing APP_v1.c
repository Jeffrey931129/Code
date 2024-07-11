#include <stdio.h>	// (2/6)
#include <limits.h>
char str[1001];
int check_palindrome(int l , int r) {
    int delete_left, delete_right;
    if(l>=r)	return  0;
    
    if(str[l]==str[r])	return check_palindrome( l+1, r-1);
    else {
		delete_left  = check_palindrome( l+1,   r);
		delete_right = check_palindrome(   l, r-1);
		return (delete_left>delete_right)? delete_right+1: delete_left+1;// choose smaller one
    }
}
int main() {
    //declare
    int n, k, ans;
    //read
    scanf("%d %d", &n ,&k);
    scanf("%s", str);
	
    ans = check_palindrome( 0, n-1);
    if(ans<=k)  printf("Yes\n");
    else        printf("No\n");
    return 0;
}
