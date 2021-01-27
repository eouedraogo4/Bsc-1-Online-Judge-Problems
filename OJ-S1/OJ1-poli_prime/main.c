#include <stdio.h>
#include <stdlib.h>

int poli(int nbr);
int prime_number(int nbre);

int main()
{
    int nbr,i,j=0;
    scanf("%d",&nbr);
    for(i=11;i<=nbr;i++)
        if(poli(i)&&prime_number(i))
            j++;
    printf("%d\n",j);
    return 0;
}


int poli(int nbr)
{
    int x=0,y;
    y=nbr;
    while(y/10!=0)
    {
        x=(x+y%10)*10;
        y=y/10;
    }
    x=x+y;
    if(x==nbr)
        x=1;
    else
        x=0;
    return x;
}

int prime_number(int nbre)
{
    int i, j=0;
    for(i=1;i<nbre;i++)
    {
        if(nbre%(nbre-i)==0)
            j++;
    }
    if(j!=1)
        j=0;
    return j;

}
