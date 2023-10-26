#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c,d,small=1;
    scanf("%d\n%d\n%d %d ",&a,&b,&c,&d);
    char array[a][a];
    for(int i=0;i<a;i++)
    {
    	for(int j=0;j<(a);j++)
        {
        	scanf(" %c",&array[i][j]);   // 特殊語法:忽略前方"space"和"enter"直到%c出現
        }
    }
    printf("%c",array[c][d]);
    for(int step=1;step<=b;step++)
    {
    	if(small)
        {
            char min=array[c-1][d-1];
            int position;
            char mini[8]={array[c-1][d-1],array[c-1][d],array[c-1][d+1],array[c][d-1],array[c][d+1],array[c+1][d-1],array[c+1][d],array[c+1][d+1]};
            if(d-1<0)
            {
                mini[0]=mini[3]=mini[5]=0;
                min=mini[4];
            }
            if(c-1<0)
            {
                mini[0]=mini[1]=mini[2]=0;
                min=mini[6];
            }
            if(d+1>=a)
            {
                mini[2]=mini[4]=mini[7]=0;
            }
            if(c+1>=a)
            {
                mini[5]=mini[6]=mini[7]=0;
            }
            for(int i=1;i<8;i++)
            {
                if(mini[i]>=65)
                {
                    min=fmin(min,mini[i]);
                }
            }
            switch(min)
            {
                case 'a':
                case 'f':
                case 'k':
                case 'p':
                case 'E':
                case 'J':
                case 'O':
                case 'T':
                    d--;
                    break;
                case 'b':
                case 'g':
                case 'l':
                case 'q':
                case 'D':
                case 'I':
                case 'N':
                case 'S':
                    d++;
                    break;
                case 'c':
                case 'h':
                case 'm':
                case 'r':
                case 'C':
                case 'H':
                case 'M':
                case 'R':
                    c--;
                    break;
                case 'd':
                case 'i':
                case 'n':
                case 's':
                case 'B':
                case 'G':
                case 'L':
                case 'Q':
                    c++;
                    break;
                case 'e':
                case 'j':
                case 'o':
                case 't':
                case 'A':
                case 'F':
                case 'K':
                case 'P':
                    for(int i=0;i<8;i++)
                    {
                        if(min==mini[i])
                        {
                            position=i+1;
                        }
                    }
                    switch(position)
                    {
                        case 1:
                            c--;d--;
                            break;
                        case 2:
                            c--;
                            break;
                        case 3:
                            c--;d++;
                            break;
                        case 4:
                            d--;
                            break;
                        case 5:
                            d++;
                            break;
                        case 6:
                            c++;d--;
                            break;
                        case 7:
                            c++;
                            break;
                        case 8:
                            c++;d++;
                            break;
                    }
                    small=0;
                    break;
                default:
                    for(int i=0;i<8;i++)
                    {
                        if(min==mini[i])
                        {
                            position=i+1;
                        }
                    }
                    switch(position)
                    {
                        case 1:
                            c--;d--;
                            break;
                        case 2:
                            c--;
                            break;
                        case 3:
                            c--;d++;
                            break;
                        case 4:
                            d--;
                            break;
                        case 5:
                            d++;
                            break;
                        case 6:
                            c++;d--;
                            break;
                        case 7:
                            c++;
                            break;
                        case 8:
                            c++;d++;
                            break;
                    }
                    break;
            }
            if(0<=c&&c<a&&0<=d&&d<a)
            {
                printf("%c",array[c][d]);
            }
            else
            {
                break;
            }
        }
        else
        {
            char max=array[c-1][d-1];
            int position;
            char maxi[8]={array[c-1][d-1],array[c-1][d],array[c-1][d+1],array[c][d-1],array[c][d+1],array[c+1][d-1],array[c+1][d],array[c+1][d+1]};
            if(d-1<0)
            {
                maxi[0]=maxi[3]=maxi[5]=0;
                max=maxi[4];
            }
            if(c-1<0)
            {
                maxi[0]=maxi[1]=maxi[2]=0;
                max=maxi[6];
            }
            if(d+1>=a)
            {
                maxi[2]=maxi[4]=maxi[7]=0;
            }
            if(c+1>=a)
            {
                maxi[5]=maxi[6]=maxi[7]=0;
            }
            for(int i=1;i<8;i++)
            {
                if(maxi[i]>=65)
                {
                    max=fmax(max,maxi[i]);
                }
            }
            switch(max)
            {
                case 'a':
                case 'f':
                case 'k':
                case 'p':
                case 'E':
                case 'J':
                case 'O':
                case 'T':
                    d--;
                    break;
                case 'b':
                case 'g':
                case 'l':
                case 'q':
                case 'D':
                case 'I':
                case 'N':
                case 'S':
                    d++;
                    break;
                case 'c':
                case 'h':
                case 'm':
                case 'r':
                case 'C':
                case 'H':
                case 'M':
                case 'R':
                    c--;
                    break;
                case 'd':
                case 'i':
                case 'n':
                case 's':
                case 'B':
                case 'G':
                case 'L':
                case 'Q':
                    c++;
                    break;
                case 'e':
                case 'j':
                case 'o':
                case 't':
                case 'A':
                case 'F':
                case 'K':
                case 'P':
                    for(int i=0;i<8;i++)
                    {
                        if(max==maxi[i])
                        {
                            position=i+1;
                        }
                    }
                    switch(position)
                    {
                        case 1:
                            c--;d--;
                            break;
                        case 2:
                            c--;
                            break;
                        case 3:
                            c--;d++;
                            break;
                        case 4:
                            d--;
                            break;
                        case 5:
                            d++;
                            break;
                        case 6:
                            c++;d--;
                            break;
                        case 7:
                            c++;
                            break;
                        case 8:
                            c++;d++;
                            break;
                    }
                    small=1;
                    break;
                default:
                    for(int i=0;i<8;i++)
                    {
                        if(max==maxi[i])
                        {
                            position=i+1;
                        }
                    }
                    switch(position)
                    {
                        case 1:
                            c--;d--;
                            break;
                        case 2:
                            c--;
                            break;
                        case 3:
                            c--;d++;
                            break;
                        case 4:
                            d--;
                            break;
                        case 5:
                            d++;
                            break;
                        case 6:
                            c++;d--;
                            break;
                        case 7:
                            c++;
                            break;
                        case 8:
                            c++;d++;
                            break;
                    }
                    break;
            }
            if(0<=c&&c<a&&0<=d&&d<a)
            {
                printf("%c",array[c][d]);
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}