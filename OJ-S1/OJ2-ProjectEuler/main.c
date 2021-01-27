#include <stdio.h>
#include <stdlib.h>

int binary_polindromic(long long x);
int polindromic(long long nbr);

int main()
{
    long long s=0,x,i;
    int time;
    scanf("%d",&time);
    for(int j=0;j<time;j++)
    {
        scanf("%lld",&x);
        s=0;
    for(i=1;i<=x;i++)
    {
        if(polindromic(i))
            if(binary_polindromic(i))
            s+=i;
    }

    printf("%lld\n",s);
    }
    return 0;
}

int polindromic(long long nbr)
{
    long long x=0,y;
    y=nbr;
    while(y/10!=0)
    {
        x=(x+y%10)*10;
        y=y/10;
    }
    x=x+y;
    if(x==nbr)
    return 1;
    else
    return 0;
}

int binary_polindromic(long long x)
{
    int z=0,i=0,j,tab[100];
    while(x/2!=0)
    {
      tab[i]=x%2;

      i++;
      x=x/2;

    }
    tab[i]=x%2;
    j=i;
    while(z<j)
    {
       if(tab[j]!=tab[z])
        return 0;
       z++;
       j--;
    }

    return 1;
}
