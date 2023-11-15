#include<stdio.h>
#include <stdlib.h>
#include"function.h"
unsigned random_seed=7122;
unsigned Random(){
	return random_seed=random_seed*0xdefaced+1;
}
int n,m,k,_;
int main(){
	
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
	
	unsigned*** array=(unsigned***)malloc(n*sizeof(unsigned**));
	/*if(array==NULL)
	{
		return 1;
	}*/
	for(int i=0;i<n;i++)
	{
		array[i]=(unsigned**)malloc(m*sizeof(unsigned*));
		/*if(array[i]==NULL)
		{
			return 1;
		}*/
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			array[i][j]=(unsigned*)malloc(k*sizeof(unsigned));
			/*if(array[i][j]==NULL)
			{
				return 1;
			}*/
		}
	}
	return array;
}

void delete_3d_array(unsigned ***arr)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			free(arr[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		free(arr[i]);
	}
	free(arr);
}