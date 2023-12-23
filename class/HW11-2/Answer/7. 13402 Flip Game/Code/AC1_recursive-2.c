#include<stdio.h>
int t,n,m;
char s[20][20];
void flip(int x,int y){
	s[x][y]^=1;
	s[x+1][y]^=1;
	s[x-1][y]^=1;
	s[x][y+1]^=1;
	s[x][y-1]^=1;
}
int check(){
	int i,j,add=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			add+=s[i][j];
	return add==0||add==n*m;
}
int MIN, cnt;
void dfs(int id){
    if(check()&&MIN>cnt) MIN = cnt;
    if(id==n*m) return;
    dfs(id+1); //the id-th bit=0
    if( cnt+1 >= MIN ) return; //prune
    flip(id/m+1, id%m+1), ++cnt;
    dfs(id+1); //the id-th bit=1
    flip(id/m+1, id%m+1), --cnt;
}
void solve(){
    MIN=7122, cnt=0;
    dfs(0);
    if(MIN==7122) puts("oops");
    else printf("%d\n",MIN);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int i,j;
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				scanf(" %c",&s[i][j]);
				s[i][j] = s[i][j]=='w';
			}
		}
		solve();
	}
	return 0;
}

