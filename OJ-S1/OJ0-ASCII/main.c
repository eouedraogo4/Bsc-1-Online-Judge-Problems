#include <stdio.h>
#include <stdlib.h>

void order(char* Tab,int tab_size);

int main()
{
    char tab[3],i;
    int x;

    while(scanf("%d",&x)!=EOF)
    {
        for(i=0;i<3;i++)
            tab[i]=getchar();
        while(getchar()!='\n');

        order(tab,3);

        for(i=2;i>=0;i--)
            printf("%c ",tab[i]);
        printf("\n");
    }
    return 0;
}


void order(char* Tab,int tab_size)
{
    int i=0,x=0,j,box;

for(j=0;j<tab_size;j++)
{
    x=tab_size;
    for(i=tab_size-2;i>=0;i--)
{
    x--;
    if(Tab[x]>Tab[i])
    {
       box=Tab[i];
       Tab[i]=Tab[x];
       Tab[x]=box;
    }
}
}
}

