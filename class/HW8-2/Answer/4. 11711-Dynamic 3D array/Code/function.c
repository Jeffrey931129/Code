#include <stdlib.h>
#include "function.h"

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k)
{
    unsigned* lk; //layer 3 for k
    unsigned** lm; //layer 2 for m
    unsigned*** ln; //layer 1 for n

    unsigned i,j;

    lk = (unsigned *) malloc(sizeof(unsigned)*n*m*k);
    lm = (unsigned **) malloc(sizeof(unsigned*)*n*m);
    ln = (unsigned ***) malloc(sizeof(unsigned**)*n);

    for(i=0;i<n;i++)
    {
        ln[i]=lm+i*m;
        for(j=0;j<m;j++)
        {
            lm[i*m+j]=lk+(i*m+j)*k;
            //or
            //ln[i][j]=lk+(i*m+j)*k;
        }
    }

    return ln;
}
void delete_3d_array(unsigned ***arr)
{
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}
