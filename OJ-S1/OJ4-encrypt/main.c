#include <stdio.h>
#include <string.h>
#define N 200

int main()
{
    int a[N],i,x,n,m,flag;
    char mot[N],result[N];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        scanf("%d",&x);
    while(x!=0)
    {
        flag=0;
        m=x;
        scanf("%s",mot);
        if(strlen(mot)<n)
            for(i=strlen(mot);i<n;i++)
            mot[i]=' ';
        while(m)
        {
            if(!flag)
            {
                for(i=0;i<n;i++)
                result[a[i]-1]=mot[i];
                flag=1;
            }
            else
            {
                for(i=0;i<n;i++)
                    mot[a[i]-1]=result[i];
                flag=0;
            }
             m--;
        }
        if(flag)
            for(i=0;i<n;i++)
            printf("%c",result[i]);
        else
        for(i=0;i<n;i++)
            printf("%c",mot[i]);
        printf("\n");
        scanf("%d",&x);
    }
    return 0;
}
