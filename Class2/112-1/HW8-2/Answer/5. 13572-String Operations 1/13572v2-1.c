#include <stdio.h>
#include <string.h>

int main(void) {
    char S[1000000+1];
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
        for(j=0;j<26;j++) if(alph[j]==A) alph[j]=B;
    }

    for(i=0;i<Slen;i++) S[i]=alph[S[i]-'a'];
    printf("%s\n",S);

    return 0;
}