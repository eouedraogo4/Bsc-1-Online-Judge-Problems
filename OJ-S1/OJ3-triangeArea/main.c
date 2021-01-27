#include <stdio.h>
#include <math.h>

int main()
{
    int time;
    double a,b,c,x1,x2,x3,y1,y2,y3,s,A;
    scanf("%d",&time);
    for(int i=0;i<time;i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));  b=sqrt(pow(x1-x3,2)+pow(y1-y3,2));  c=sqrt(pow(x3-x2,2)+pow(y3-y2,2));

        if(a+b>c&&a+c>b&&b+c>a)
        {
            s=(a+b+c)/2;
            A=sqrt(s*(s-a)*(s-b)*(s-c));
            printf("%.2lf\n",A);
        }
        else
            printf("fail\n");

    }

    return 0;
}
