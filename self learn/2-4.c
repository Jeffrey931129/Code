#include <stdio.h>

int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    double average=(x+y+z)/3;
    // average的表示法為一個int   
    printf("%f\n",average);
    average=(x+y+z)/(double)3;
    // 將average顯性轉型為double
    printf("%f\n",average);
    average=(x+y+z)/3.;
    // 將average隱性轉型為double
    printf("%f",average);
    return 0;
}
// double使用%lf輸入、%f輸出