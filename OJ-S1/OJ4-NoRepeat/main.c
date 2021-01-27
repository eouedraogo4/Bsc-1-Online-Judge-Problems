#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *tab, n,j,i;
    while(n!=-1)
    {
        j=1;
        scanf("%d",&n);
   tab=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&tab[i]);
    for(int i=1;i<n;i++)
    {
        while(tab[i]==tab[i-1])
            i++;
        if(i<n)
        {
           tab[j]=tab[i];
           j++;
        }
        else
            tab[j]=tab[n-1];
    }
   for(int i=0;i<j;i++)
    printf("%d ",tab[i]);
    }

    return 0;
}
