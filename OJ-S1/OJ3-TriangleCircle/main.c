#include <stdio.h>
#include <math.h>

 struct point
{
    double x,y;
};

double dis(struct point p1,struct point p2)
{
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

double Area(struct point p1, struct point p2, struct point p3)
{
    double s,a=dis(p1,p2),b=dis(p1,p3),c=dis(p2,p3);
    s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double cos_angle(struct point p,struct point p1,struct point p2)
{
    double a=dis(p1,p2),b=dis(p,p1),c=dis(p,p2);
    return (b*b+c*c-a*a)/(2*b*c);
}

int main()
{
    int flag,j,time;
    struct point cir,p[3];
    double R,h,d0,d1,d2;
    scanf("%d",&time);
    for(int i=0;i<time;i++)
    {
        flag=0;
        scanf("%lf%lf%lf",&cir.x,&cir.y,&R);
        for(j=0;j<3;j++)
            scanf("%lf%lf",&p[j].x,&p[j].y);
        d0=dis(cir,p[0]); d1=dis(cir,p[1]); d2=dis(cir,p[2]);

        if(d0==R||d1==R||d2==R)
            printf("Yes\n");
        else if(d0<R&&d1<R&&d2<R)
            printf("No\n");
        else if(d0<R||d1<R||d2<R)
            printf("Yes\n");
        else
        {
            for(j=0;j<3;j++)
                {
                    h=2*Area(cir,p[j%3],p[(j+1)%3])/dis(p[j%3],p[(j+1)%3]);

                    if(h<=R)
                    {
                        double a0=cos_angle(p[j%3],p[(j+1)%3],cir); double a1=cos_angle(p[(j+1)%3],p[j%3],cir);
                        if(a0<=1&&a0>=0&&a1>=0&&a1<=1)
                        {
                            flag=1;
                            break;
                        }
                    }

                }
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
