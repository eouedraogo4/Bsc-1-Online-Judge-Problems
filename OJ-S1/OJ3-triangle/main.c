#include <stdio.h>

int main()
{
    double a,b,c;
    int time;
    scanf("%d",&time);
    for(int i=0;i<time;i++)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
    if(a+b>c&&a+c>b&&b+c>a)
        printf("YES\n");
    else
        printf("NO\n");
    }
    return 0;
}
