#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x;
    while(scanf("%lf",&x)!=EOF)
    {
        if(x<0)
        x=-x;
        printf("%-5.2lf\n",x);
    }
    return 0;
}
