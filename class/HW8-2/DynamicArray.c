#include<stdio.h>
#include<stdlib.h>
#include"function.h"
unsigned random_seed=7122;
unsigned Random(){
	return random_seed=random_seed*0xdefaced+1;
}

int main(){
	int n,m,k,_;
	scanf("%d%d%d%d%u",&_,&n,&m,&k,&random_seed);
	while(_--){
		unsigned ***arr=new_3d_array(n,m,k);
		int i,j,l;
		for(i=0;i<n;++i){
			for(j=0;j<m;++j){
				for(l=0;l<k;++l){
					arr[i][j][l]=Random();
				}
			}
		}
		for(i=0;i<5;++i){
			unsigned a,b,c;
			a=Random()%n;
			b=Random()%m;
			c=Random()%k;
			if(i)putchar(' ');
			printf("%u",arr[a][b][c]);
		}
		puts("");
		delete_3d_array(arr);
	}
	return 0;
}

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k)
{
	unsigned* arr1=malloc(n*m*k*sizeof(unsigned));
	unsigned** arr2=malloc(n*m*sizeof(unsigned*));
	unsigned*** arr3=malloc(n*sizeof(unsigned**));
	for(int i=0;i<n*m;i++)
	{
		arr2[i]=&arr1[i*k];
	}
	for(int i=0;i<n;i++)
	{
		arr3[i]=&arr2[i*m];
	}
	return arr3;
}

void delete_3d_array(unsigned ***arr)
{
	free(arr[0][0]);
	free(arr[0]);
	free(arr);
}
	