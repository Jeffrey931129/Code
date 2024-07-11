#include<stdio.h>
int t,n,m;
char s[20][20];
int bit_cnt(int d){
	int cnt=0;
	for(;d;d>>=1)
		if(d&1) ++cnt;
	return cnt;
}
void flip(int x,int y){
	s[x][y]^=1;
	s[x+1][y]^=1;
	s[x-1][y]^=1;
	s[x][y+1]^=1;
	s[x][y-1]^=1;
}
void flip_all(int ST){
	int i;
	for(i=0;i<n*m;++i)
		if(ST&(1<<i)) flip(i/m+1,i%m+1);
}
int check(){
	int i,j,add=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			add+=s[i][j];
	return add==0||add==n*m;
}
void solve(){
    int ST, MIN=7122; 
    for(ST=0;ST<(1<<(n*m));++ST){
        flip_all(ST);
        int b_cnt = bit_cnt(ST);
        if(check()&&MIN>b_cnt) MIN=b_cnt;
        flip_all(ST); 
    }
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

