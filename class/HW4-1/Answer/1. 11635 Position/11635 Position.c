#include <stdio.h>
#include <string.h>

char str[1000001];

int main()
{
   char ch;
   int len;
   int found;

   int i;

   scanf("%s", str); /*AbAABzBCAaa*/
   len = strlen(str);

   ch = 'A'; //initialize
   while (ch<='z') {
        found = 0;
        for (i=0; i<len; i++) {
            if (str[i] == ch) {
                if (!found) {
                    printf("%c: %d", ch, i);
                    found = 1;
                } else {
                    printf(" %d", i);
                }
            }
        }

        if (found)
            printf("\n");

        ch++; //update
   }
}
