#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415927

int main()
{
    float r,v;
    while(scanf("%f",&r)!=EOF)
    {
        v=(4*PI*r*r*r)/3;
    printf("%-5.3f\n",v);
    }
    return 0;
}
