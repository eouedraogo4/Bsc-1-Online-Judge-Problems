#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tab[10],temp;

   while(scanf("%s",tab)!=EOF)
    {
        if(tab[0]>tab[1])
        {
            temp=tab[0];
            tab[0]=tab[1];
            tab[1]=temp;
        }

        if(tab[1]<tab[2])
            {
               temp=tab[1];
            tab[1]=tab[2];
            tab[2]=temp;
            }

              if(tab[0]>tab[1])
        {
            temp=tab[0];
            tab[0]=tab[1];
            tab[1]=temp;
        }
    }
    printf("%c %c %c\n",tab[0],tab[1],tab[2]);
    return 0;
}
