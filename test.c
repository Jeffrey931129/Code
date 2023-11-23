#include <stdio.h>
#define MAX 10
#define swap(a, b) if (a != b) {(*a)^=(*b); (*b)^=(*a); (*a)^=(*b);}

void selection_sort(int* a, int size);
int a[MAX] = {3, 7, 9, 1, 4, 0, 8, 6, 2, 5},get_min(int*,int);

int main(void) {
    selection_sort(a, MAX);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void selection_sort(int* a,int size)
{
    int min;
    if(size==1)
    {
        return;
    }
    min=get_min(a,size);
    swap(&a[0],&a[min]);
    selection_sort(a+1,size-1);
}

int get_min(int* a,int size)
{
    if(size==1)
    {
        return 0;
    }
    int min=get_min(a+1,size-1)+1;
    if(*(a+min)>*a)
    {
        return 0;
    }
    return min;
}