#include <stdio.h>

int main()
{
    int n,a,b;
    scanf("%d",&n);
    while(n!=-1)
    {
        scanf("%d",&a);
        b=a;
        printf("%d ",b);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&a);
            if(a>b)
            {
                b=a;
                printf("%d ",b);
            }
        }
        printf("\n");
        scanf("%d",&n);
    }

    return 0;
}
