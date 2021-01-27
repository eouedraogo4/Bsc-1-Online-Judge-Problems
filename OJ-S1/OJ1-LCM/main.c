#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long i=1,x,y;
    scanf("%lld%lld",&x,&y);
    while((x*i)%y!=0)
        i++;
    printf("%lld\n",x*i);
    return 0;
}
