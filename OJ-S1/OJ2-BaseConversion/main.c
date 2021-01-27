#include <stdio.h>
#include <stdlib.h>

int convert(int x, int y);

int main()
{
    int x,y,i=0,tab[100];
    scanf("%d%d",&x,&y);
    while(x/y!=0)
    {
      tab[i]=convert(x, y);
      i++;
      x=x/y;

    }
    tab[i]=convert(x,y);

    for(int j=i;j>=0;j--)
        {
            if(tab[j]<=10)
                printf("%d",tab[j]);
            else
               printf("%c",tab[j]);

        }


    return 0;
}

int convert(int x, int y)
{
    int i;
     if(y>=10)
        {
            switch(x%y)
            {
            case 10:
                i='A';
                break;
            case 11:
                i='B';
                break;
            case 12:
                i='C';
                break;
            case 13:
                i='D';
                break;
            case 14:
                i='E';
                break;
            case 15:
                i='F';
                break;
            default:
                i=x%y;
                break;

            }
        }
    else
      i=x%y;
      return i;
}
