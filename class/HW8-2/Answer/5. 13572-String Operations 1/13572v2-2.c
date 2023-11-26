#include <stdio.h>
#include <string.h>

int main(void){
    char S[1000000+1];
    char O[100000][2];//operations
    int Slen;
    char alph[26];

    int Q;
    char A,B;

    int i,j;

    scanf("%s",S);
    Slen=strlen(S);

    for(i=0;i<26;i++) alph[i]=i+'a';
    scanf("%d",&Q);
    for(i=0;i<Q;i++) {
        scanf("\n%c %c",&A,&B);
        O[i][0]=A; O[i][1]=B;
    }
    for(i=Q-1;i>=0;i--) alph[O[i][0]-'a']=alph[O[i][1]-'a'];

    for(i=0;i<Slen;i++) S[i]=alph[S[i]-'a'];
    printf("%s\n",S);

    return 0;
}