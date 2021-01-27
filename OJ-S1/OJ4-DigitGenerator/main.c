#include <stdio.h>

int main()
{
    int x,y,nbre,i,time,j,ans[100005]={0};
    for(i=0;i<100005;i++)
    {
         x=i;
        y=i;
        while(y)
            {
                x+=y%10;
                y/=10;
            }
        if(ans[x]==0||i<ans[x]) ans[x]=i;
    }

    scanf("%d",&time);
    for(j=0;j<time;j++)
    {
        scanf("%d",&nbre);
        printf("%d\n",ans[nbre]);
    }
    return 0;
}
