#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char letter[26];
void shuffle(FILE* open)
{
    int time=rand()%50;
    for(int i=0;i<time;i++)
    {
        int j=rand()%26,k=rand()%26;
        char temp=letter[j];
        letter[j]=letter[k];
        letter[k]=temp;
    }
}

int main()
{
    srand(time(NULL));
    int time=rand()%10+1;
    for(int i=0;i<26;i++)
    {
        letter[i]='a'+i;
    }
    FILE *open=fopen("Example.txt","w");
    fprintf(open,"%d\n",time);
    //shuffle(open);
    fprintf(open,"%s\n",letter);
    while(time--)
    {
        for(int i=0;i<6;i++)
        {
            char rander=rand()%26+'a';
            fprintf(open,"%c",rander);
        }
        fprintf(open," ");
    }
}