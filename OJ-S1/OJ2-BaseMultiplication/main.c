#include <stdio.h>

int big_digit(unsigned long long x);
unsigned long long convert(unsigned long long x,int base);


int main()
{
    int x,yes=0,i=0;
    unsigned long long p,q,r,tab[3];
    scanf("%lld%lld%lld",&p,&q,&r);
    tab[0]=big_digit(p); tab[1]=big_digit(q); tab[2]=big_digit(r);

for(int j=0;j<3;j++)
{
    x=3;
    for(i=1;i>=0;i--)
{
    x--;
    if(tab[x]>tab[i])
    {
      int box=tab[i];
       tab[i]=tab[x];
       tab[x]=box;
    }
}
}
    i=tab[0];

 while(i<16&&yes==0)
  {
      i++;
        tab[0]=convert(p,i); tab[1]=convert(q,i); tab[2]=convert(r,i);
        if(tab[0]*tab[1]==tab[2])
            yes=1;
    }

    if(yes)
    printf("%d\n",i);
    else
        printf("%d\n",0);
    return 0;
}

int big_digit(unsigned long long x)
{
    int i,ten=10,tmp=0,j=1;
    while(x/ten!=0)
    {
        j++;
        ten*=10;
    }
    ten/=10;

    for(i=0;i<j;i++)
    {
        if(tmp<x/ten)
            tmp=x/ten;
        x%=ten;
        ten/=10;
    }
    return tmp;
}

unsigned long long convert(unsigned long long x,int base)
{
    int i=0,remainder,produit=1;
    unsigned long long s=0;
    while(x!=0)
    {
        produit=1;
        remainder=x%10;
        for(int j=0;j<i;j++)
            produit*=base;
        s+=remainder*produit;
        i++;
        x/=10;
    }

	return s;
}
