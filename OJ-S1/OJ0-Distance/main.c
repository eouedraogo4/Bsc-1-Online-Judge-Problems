#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    float x1,y1,x2,y2;
    while(scanf("%f%f%f%f",&x1,&y1,&x2,&y2)!=EOF)
    {
        x1=x1-x2;
        x1*=x1;
        y2=y1-y2;
        y2*=y2;
        printf("%-5.2f\n",sqrt(x1+y2));
    }
    return 0;
}
