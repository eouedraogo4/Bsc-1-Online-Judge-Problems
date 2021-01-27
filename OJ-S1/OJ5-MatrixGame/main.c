#include <stdio.h>
#define MAX_N 200

void Qshort(int* tab,int first,int last);

int main()
{
    int matrix[MAX_N]={0};
    int N,i,j;
    scanf("%d",&N);
    int tmp;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d",&tmp);
            matrix[j] += tmp;
        }
    }
    Qshort(matrix,0,N-1);
    for (i = 0;i<N-1 && matrix[i] + matrix[i + 1]< 0; i += 2)
    {
        matrix[i] *= -1;
        matrix[i + 1] *= -1;
    }
    int sum = 0;
    for (i = 0; i < N; i++)
    {
        sum += matrix[i];
    }
    printf("%d ",sum);
    return 0;
}

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
