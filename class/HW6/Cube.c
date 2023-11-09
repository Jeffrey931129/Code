#include <stdio.h>

int success=0;
int cube(int,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char,char);
char ch[25];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n; 
        
        scanf("%d",&n);
        scanf("%s",ch);
        //printf("%s\n",ch);
        
        success=0;
        
            
        cube(n,ch[0],ch[1],ch[2],ch[3],ch[4],ch[5],ch[6],ch[7],ch[8],ch[9],ch[10],ch[11],ch[12],ch[13],ch[14],ch[15],ch[16],ch[17],ch[18],ch[19],ch[20],ch[21],ch[22],ch[23]);
        
        if(success)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        
    }
}

int cube(int n,char cube1,char cube2,char cube3,char cube4,char cube5,char cube6,char cube7,char cube8,char cube9,char cube10,char cube11,char cube12,char cube13,char cube14,char cube15,char cube16,char cube17,char cube18,char cube19,char cube20,char cube21,char cube22,char cube23,char cube24)
{
    
    if(cube1==cube2&&cube1==cube3&&cube1==cube4&&cube5==cube6&&cube5==cube7&&cube5==cube8&&cube9==cube10&&cube9==cube11&&cube9==cube12&&cube13==cube14&&cube13==cube15&&cube13==cube16&&cube17==cube18&&cube17==cube19&&cube17==cube20&&cube21==cube22&&cube21==cube23&&cube21==cube24)
    {
        
        success++; return 1;
    }
    if(n==0)
    {
        return 0;
    }
    /*if(cube(n-1,cube2,cube4,cube1,cube3,cube17,cube18,cube7,cube8,cube5,cube6,cube11,cube12,cube9,cube10,cube15,cube16,cube13,cube14,cube19,cube20,cube21,cube22,cube23,cube24))  
    {  // 上面一層往右轉
        return 1;  
    }*/
    if(cube(n-1,cube3,cube1,cube4,cube2,cube9,cube10,cube7,cube8,cube13,cube14,cube11,cube12,cube17,cube18,cube15,cube16,cube5,cube6,cube19,cube20,cube21,cube22,cube23,cube24))  
    {  // 上面一層往左轉
        return 1;
    }
    
    /*if(cube(n-1,cube9,cube2,cube11,cube4,cube6,cube8,cube5,cube7,cube21,cube10,cube23,cube12,cube13,cube14,cube15,cube16,cube17,cube3,cube19,cube1,cube20,cube22,cube18,cube24))
    {  // 左邊一層往上
        return 1;
    }*/
    if(cube(n-1,cube20,cube2,cube18,cube4,cube7,cube5,cube8,cube6,cube1,cube10,cube3,cube12,cube13,cube14,cube15,cube16,cube17,cube23,cube19,cube21,cube9,cube22,cube11,cube24))
    {  // 左邊一層往下
        return 1;
    }
    
    /*if(cube(n-1,cube1,cube2,cube13,cube15,cube5,cube4,cube7,cube3,cube10,cube12,cube9,cube11,cube22,cube14,cube21,cube16,cube17,cube18,cube19,cube20,cube6,cube8,cube23,cube24))
    {  // 前面一層往左
        return 1;
    }*/
    if(cube(n-1,cube1,cube2,cube8,cube6,cube5,cube21,cube7,cube22,cube11,cube9,cube12,cube10,cube3,cube14,cube4,cube16,cube17,cube18,cube19,cube20,cube15,cube13,cube23,cube24))
    {  // 前面一層往右
        return 1;
    }
    
    return 0;
}
