#include <stdio.h>

int main()

{

    int i,j,y,tab[1000];
    for(i=0;i<=1000;i++) tab[i]=1;
	tab[0] = 0; tab[1] = 0;
	for(i=2; i<=1000;i++)
			for(j=i; j<=1000/i; j++)
				tab[i*j] = 0;

    while(scanf("%d",&y)!=EOF&&y!=0)
    {
        j=0;
        for(i=2;i<y/2;i++)
            if(tab[i]&&tab[y-i])
                  j++;
    printf("%d\n",j);
    }

    return 0;
}
