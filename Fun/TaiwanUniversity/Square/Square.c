#include <stdio.h>
#include <math.h>

int angle(int,int,int,int);

int main()
{
    /*FILE *inputFile; // 定義一個指向輸入檔案的指針
    FILE *outputFile; // 定義一個指向輸出檔案的指針
    char inputFilename[] = "D:\\Jeffrey\\code\\class\\Fun\\TaiwanUniversity\\11-1.in"; // 輸入檔案名稱
    char outputFilename[] = "D:\\Jeffrey\\code\\class\\Fun\\TaiwanUniversity\\test.txt"; // 輸出檔案名稱
    inputFile = fopen(inputFilename, "r");

    if (inputFile == NULL) {
        perror("無法打開輸入檔案"); // 若無法打開輸入檔案，輸出錯誤信息
        return 1; // 結束程式
    }
    outputFile = fopen(outputFilename, "w");

    if (outputFile == NULL) {
        perror("無法打開輸出檔案"); // 若無法打開輸出檔案，輸出錯誤信息
        fclose(inputFile); // 關閉輸入檔案
        return 1; // 結束程式
    }
    int n_square=0,n_diamond=0,n_rectangle=0;*/
    
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        int p1[2],p2[2],p3[2],p4[2];
        scanf("%d%d%d%d%d%d%d%d",&p1[0],&p1[1],&p2[0],&p2[1],&p3[0],&p3[1],&p4[0],&p4[1]);
        int x1=(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]),x2=(p3[0]-p1[0])*(p3[0]-p1[0])+(p3[1]-p1[1])*(p3[1]-p1[1]),x3=(p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1]);
        int c2=fmax(x1,fmax(x2,x3)),a2=fmin(x1,fmin(x2,x3)),b2=x1+x2+x3-fmax(x1,fmax(x2,x3))-fmin(x1,fmin(x2,x3));
        if(c2==a2+b2)   // 正方、長方or other                    ////////  最長邊不一定被夾在中間
        {
            if(a2==b2)   // 正方or other
            {
                if(c2==x1)
                {
                    if(angle(p3[0]-p1[0],p3[1]-p1[1],p4[0]-p1[0],p4[1]-p1[1])&&angle(p2[0]-p4[0],p2[1]-p4[1],p4[0]-p1[0],p4[1]-p1[1])&&((p2[0]-p4[0])==(p3[0]-p1[0]))&&((p2[1]-p4[1])==(p3[1]-p1[1])))
                    {
                        printf("square\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
                else if(c2==x2)
                {
                    if(angle(p2[0]-p1[0],p2[1]-p1[1],p4[0]-p1[0],p4[1]-p1[1])&&angle(p3[0]-p4[0],p3[1]-p4[1],p4[0]-p1[0],p4[1]-p1[1])&&((p3[0]-p4[0])==(p2[0]-p1[0]))&&((p3[1]-p4[1])==(p2[1]-p1[1])))
                    {
                        printf("square\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
                else
                {
                    if(angle(p3[0]-p1[0],p3[1]-p1[1],p2[0]-p1[0],p2[1]-p1[1])&&angle(p2[0]-p4[0],p2[1]-p4[1],p2[0]-p1[0],p2[1]-p1[1])&&((p4[0]-p2[0])==(p3[0]-p1[0]))&&((p4[1]-p2[1])==(p3[1]-p1[1])))
                    {
                        printf("square\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
            }
            else   // 長方or other                                    
            {
                if(c2==x1)
                {
                    if(angle(p3[0]-p1[0],p3[1]-p1[1],p4[0]-p1[0],p4[1]-p1[1])&&angle(p2[0]-p4[0],p2[1]-p4[1],p4[0]-p1[0],p4[1]-p1[1])&&((p2[0]-p4[0])==(p3[0]-p1[0]))&&((p2[1]-p4[1])==(p3[1]-p1[1])))
                    {
                        printf("rectangle\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
                else if(c2==x2)
                {
                    if(angle(p2[0]-p1[0],p2[1]-p1[1],p4[0]-p1[0],p4[1]-p1[1])&&angle(p3[0]-p4[0],p3[1]-p4[1],p4[0]-p1[0],p4[1]-p1[1])&&((p3[0]-p4[0])==(p2[0]-p1[0]))&&((p3[1]-p4[1])==(p2[1]-p1[1])))
                    {
                        printf("rectangle\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
                else
                {
                    if(angle(p3[0]-p1[0],p3[1]-p1[1],p2[0]-p1[0],p2[1]-p1[1])&&angle(p2[0]-p4[0],p2[1]-p4[1],p2[0]-p1[0],p2[1]-p1[1])&&((p4[0]-p2[0])==(p3[0]-p1[0]))&&((p4[1]-p2[1])==(p3[1]-p1[1])))
                    {
                        printf("rectangle\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
            }
        }
        else   // 菱形or other
        {
            if(a2==b2&&b2==c2)
            {
                if(pow((p2[0]-p1[0])*(p3[0]-p1[0])+(p2[1]-p1[1])*(p3[1]-p1[1]),2)/x1/x2==0.25)
                {
                    if(pow((p4[0]-p1[0])*(p3[0]-p1[0])+(p4[1]-p1[1])*(p3[1]-p1[1]),2)/x3/x2==0.25)
                    {
                        printf("diamond\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
                else
                {
                    printf("other\n");
                }
            }
            else if(a2==b2||b2==c2)
            {
                if(x1==x2)
                {
                    if(pow(p4[0]-p2[0],2)+pow(p4[1]-p2[1],2)==x1&&pow(p4[0]-p3[0],2)+pow(p4[1]-p3[1],2)==x1)
                    {
                        printf("diamond\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
                else if(x1==x3)
                {
                    if(pow(p3[0]-p2[0],2)+pow(p3[1]-p2[1],2)==x1&&pow(p3[0]-p4[0],2)+pow(p3[1]-p4[1],2)==x1)
                    {
                        printf("diamond\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
                else
                {
                    if(pow(p4[0]-p2[0],2)+pow(p4[1]-p2[1],2)==x2&&pow(p2[0]-p3[0],2)+pow(p2[1]-p3[1],2)==x2)
                    {
                        printf("diamond\n");
                        
                    }
                    else
                    {
                        printf("other\n");
                    }
                }
            }
            else
            {
                printf("other\n");
            }
        }
    }
    /*printf("%d %d %d",n_square,n_diamond,n_rectangle);

    fclose(inputFile);
    fclose(outputFile);*/



    return 0;
}

int angle(int h1,int h2,int h3,int h4)
{
    if(h1==0||h3==0)
    {
        if((h1==0&&h4==0)||(h2==0&&h3==0))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(h2*h4/h1/h3==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}