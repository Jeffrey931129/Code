#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d, e, f, g, h;
        scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
        if ( (e - a) * (h - b) - (f - b) * (g - a) > 0 && 
        (e - a) * (d - b) - (f - b) * (c - a)> 0 ){
            int tmp;
            tmp = c;
            c = e;
            e = tmp;
            tmp = d;
            d = f;
            f = tmp;
        }
        if ( (g - a) * (d - b) - (h - b) * (c - a) > 0&& 
        (g - a) * (f - b) - (h - b) * (e - a) > 0){
            int tmp;
            tmp = c;
            c = g;
            g = tmp;
            tmp = d;
            d = h;
            h = tmp;
        }
        if ( (g - a) * (f - b) - (h - b) * (e - a) > 0){
            int tmp;
            tmp = e;
            e = g;
            g = tmp;
            tmp = f;
            f = h;
            h = tmp;
        }
        int x, y, z, o, p;
        x = (a - c) * (a - c) + (b - d) * (b - d);
        y = (c - e) * (c - e) + (d - f) * (d - f);
        z = (e - g) * (e - g) + (f - h) * (f - h);
        o = (g - a) * (g - a) + (h - b) * (h - b);
        p = (a - e) * (a - e) + (b - f) * (b - f);
        if((x == y) &&(y == z) &&(z == o) &&(p == x + y)){
            printf("square\n");
        }
        else if((x == y) &&(y == z) &&(z == o) &&(p != x + y)){
            printf("diamond\n");
        }
        else if((x == z) &&(y == o)&&(p == x + y)){
            printf("rectangle\n");
        }
        else
            printf("other\n");


        
    }
}