#include <stdio.h>
#include <string.h>

int main()
{
    int i,time;
    double M,n,sum;
    char tab[80];
    scanf("%d",&time);
    while(time--)
    {
        sum=0;
        scanf("%s",tab);
        for(i=0;i<strlen(tab);i++)
        {
            if(tab[i]<='9') continue;
            if(tab[i]=='C') M=12.01;
            if(tab[i]=='H') M=1.008;
            if(tab[i]=='O') M=16.00;
            if(tab[i]=='N') M=14.01;
            int p=i+1;
            if(tab[p]>'0'&&tab[p]<='9')
            {
                n=0;
                while(tab[p]>'0'&&tab[p]<='9')
                {
                    n=(n*10)+(tab[p]-'0');
                    p++;
                }
            }
            else
                n=1;
            sum+=M*n;
        }
        printf("%.3lf\n",sum);

    }
    return 0;
}
