#include <stdio.h>
#include <stdlib.h>

/*un nombre polindromique
est un nombre qui reste
le meme quand on le renverse
11, 101,121,5445
*/
int main()
{
    int nbr=0,x=0,y;
    scanf("%d",&nbr);
    y=nbr;
    while(y/10!=0)
    {
        x=(x+y%10)*10;
        y=y/10;
    }
    x=x+y;
    if(x==nbr)
    printf("yes\n");
    else
        printf("no\n");
    return 0;
}
