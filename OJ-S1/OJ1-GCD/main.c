#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z;
    scanf("%d%d",&y,&z);
    while(y%z!=0)
    {
        x=z;
        z=y%z;
        y=x;


    }

    printf("%d 0x%x 0%o\n",z,z,z);
    return 0;
}
