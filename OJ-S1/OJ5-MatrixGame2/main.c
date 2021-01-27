#include <stdio.h>
#define MAX_N 200

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
        while(i<j&&tab[i]<pivot)
            ++i;
        tab[j]=tab[i];
    }
    tab[i]=pivot;
    Qshort(tab,first,i-1);
    Qshort(tab,i+1,last);
}

int main()
{
    int matrix[MAX_N]={0},tab[MAX_N][MAX_N],N;
    scanf("%d",&N);
     for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d",&tab[i][j]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matrix[j] += tab[i][j];

    Qshort(matrix,0,N-1);
    for (int i = 0;matrix[i] + matrix[i + 1]< 0&&i<N; i += 2)
    {
        matrix[i] *= -1;
        matrix[i + 1] *= -1;
    }
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += matrix[i];
    }
    printf("%d",sum);
    return 0;
}
