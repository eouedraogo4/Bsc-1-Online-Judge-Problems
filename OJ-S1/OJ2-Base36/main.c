#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char tab[100];
    scanf("%s",tab);
    for(int i=0;i<strlen(tab);i++)
    printf("%c\n",tab[i]);
    return 0;
}

int polindromic(int nbre)
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
    return 1;
    else
    return 0;
}
