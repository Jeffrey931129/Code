#include <stdio.h>

int main()
{
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    double average=(x+y+z)/3;
    // average����ܪk���@��int   
    printf("%f\n",average);
    average=(x+y+z)/(double)3;
    // �Naverage����૬��double
    printf("%f\n",average);
    average=(x+y+z)/3.;
    // �Naverage�����૬��double
    printf("%f",average);
    return 0;
}
// double�ϥ�%lf��J�B%f��X