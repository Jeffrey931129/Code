#include <stdio.h>
#include <string.h>

int main(void) {
    char S[1000000+1];
    int Slen;

    int Q;
    char A,B;

    int i,j;

    scanf("%s",S);
    Slen=strlen(S);

    scanf("%d",&Q);
    for(i=0;i<Q;i++) {
        scanf("\n%c %c",&A,&B);
        for(j=0;j<Slen;j++) if(S[j]==A) S[j]=B;
    }

    printf("%s\n",S);

    return 0;
}