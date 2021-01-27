#include <stdio.h>
#include <string.h>

char name[101][20];
int tab[101][3];
void Qshort(int first,int last,int mode);

int main()
{
    int first=0, last=0;
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",name[i]);
        for(j=0;j<3;j++)
            scanf("%d",&tab[i][j]);
    }

    Qshort(0,n-1,0);

    for(i=0;i<n;i++)
    {
        while(tab[i][0]!=tab[i+1][0]&&i<n)
            i++;
        first=i;
        while(tab[i][0]==tab[i+1][0]&&i<n)
            i++;
        last=i;
        Qshort(first,last,1);
    }

    for(i=0;i<n;i++)
    {
        while(tab[i][1]!=tab[i+1][1]&&i<n)
            i++;
        first=i;
        while(tab[i][1]==tab[i+1][1]&&i<n)
            i++;
        last=i;
        Qshort(first,last,2);
    }

    for(i=0;i<n;i++)
    {
        if(tab[i][2]!=tab[i+1][2])
            printf("%s\n",name[i]);
        else
        {
            printf("%s\n",name[i+1]);
            printf("%s\n",name[i]);
            i++;
        }
    }

    return 0;
}

void Qshort(int first,int last,int mode)
{

    if(first>=last)
        return;
    int i=first;
    int j=last;
    int pivot[1][3];
    for(int n=0;n<3;n++)
        pivot[0][n]=tab[first][n];
    char tmp[1][20]; strcpy(tmp[0],name[first]);
    while(i<j)
    {
        while(i<j&&tab[j][mode]>=pivot[0][mode])
            --j;
        for(int n=0;n<3;n++)
          tab[i][n]=tab[j][n];
        strcpy(name[i],name[j]);
        while(i<j&&tab[i][mode]<=pivot[0][mode])
            ++i;
        for(int n=0;n<3;n++)
            tab[j][n]=tab[i][n];
        strcpy(name[j],name[i]);
    }
    for(int n=0;n<3;n++)
        tab[i][n]=pivot[0][n];
    strcpy(name[i],tmp[0]);
    Qshort(first,i-1,mode);
    Qshort(i+1,last,mode);
}
