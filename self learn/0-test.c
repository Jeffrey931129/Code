#include <stdio.h>

int main(void) {
    char cl[3][3];
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            scanf("%c",&cl[x][y]);
            
        }
    }
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            printf("%c",cl[x][y]);
        }
        printf("\n");
    }
    return 0;
}
// test