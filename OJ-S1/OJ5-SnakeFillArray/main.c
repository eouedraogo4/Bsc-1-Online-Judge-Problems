#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,x,y,nbre,flag,N;
    scanf("%d",&N);
    int **tab=malloc(sizeof *tab * N);
    if(tab)
    {
        for(i=0;i<N;i++)
            tab[i]=malloc(sizeof *tab[i] * N);
    }

    x=0; y=0; nbre=1;flag=1;
    while(x<N&&y<N)
    {
     i=x; j=y;
    while(i!=y&&j!=x)
    {
        if(flag)
            tab[i--][j++]=nbre;
        else
            tab[i++][j--]=nbre;
        nbre++;
    }
    tab[i][j]=nbre;
    nbre++;
    if(!flag)
    {
        x=y+1;
        y=0;
        flag=1;
    }
    else
    {
        y=x+1;
        x=0;
        flag=0;
    }
    }

    x=N-1; y=N-1; nbre=N*N; flag=1;
    while(x>0&&y>0)
    {
        i=x; j=y;
        while(i!=y&&j!=x)
        {
         if(!flag)
            tab[i--][j++]=nbre;
         else
            tab[i++][j--]=nbre;
         nbre--;
        }
        tab[i][j]=nbre;
        nbre--;
        if(!flag)
        {
            x=y-1;
            y=N-1;
            flag=1;
        }
        else
        {
            y=x-1;
            x=N-1;
            flag=0;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",tab[i][j]);
        printf("\n");
    }
    return 0;
}
