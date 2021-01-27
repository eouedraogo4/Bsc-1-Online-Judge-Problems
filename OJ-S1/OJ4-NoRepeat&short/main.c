#include <stdio.h>
#include <stdlib.h>

void Qshort(int* tab,int first,int last)
{
    if(first>=last)
        return;
    int i=first;
    int j=last;
    int pivot=tab[first];
    while(i<j)
    {
        while(i<j&&tab[j]>=pivot)
            --j;
        tab[i]=tab[j];
        while(i<j&&tab[i]<=pivot)
            ++i;
        tab[j]=tab[i];
    }
    tab[i]=pivot;
    Qshort(tab,first,i-1);
    Qshort(tab,i+1,last);
}

int main()
{
    int *tab,i,n;
    scanf("%d",&n);
    tab=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&tab[i]);
    Qshort(tab,0,n-1);
    printf("%d ",tab[0]);
    for(i=1;i<n;i++)
    {
        if(tab[i]!=tab[i-1])
            printf("%d ",tab[i]);
    }
    return 0;
}
