#include <stdio.h>
#include <math.h>

double max(double x, double y)
{
    if(x>y)
        return x;
    else
        return y;
}
double min(double x, double y)
{
    if(x<y)
        return x;
    else
        return y;
}

int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

    double maxx=max(x1,x2), minx=min(x1,x2),maxy=max(y1,y2),miny=min(y1,y2);

    double bigx=max(x3,x4);
    double smax=min(x3,x4);
    double bigy=max(y3,y4);
    double smay=min(y3,y4);

    if(smax>=maxx||minx>=bigx||smay>=maxy||miny>=bigy)
        printf("0\n");
    else
    {
        double xx=max(minx,smax);
        double yy=max(miny,smay);
        double x=min(maxx,bigx);
        double y=min(maxy,bigy);
        printf("%lf\n",fabs((x-xx)*(y-yy)));
    }
    return 0;
}
