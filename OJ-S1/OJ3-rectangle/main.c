#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void swap(int* x,int* y)
{
    int z;
    z=*x;
    *x=*y;
    *y=z;
}
void bubbleSort(int* A )
{
    int n=4,newn;
    while(n>1)
        {
            newn = 0;
            for(int i=1;i<=n-1;i++)
                {
                    if(A[i-1] > A[i])
                    {
                        swap(&A[i-1], &A[i]);
                        newn = i;
                    }
                }
            n = newn;
        }
}


int main()
{
    int i,j;
    int A[2][4],s;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        scanf("%d",&A[j][i]);
    for(i=2;i<4;i++)
        for(j=0;j<2;j++)
        scanf("%d",&A[j][i]);

        if(A[0][0]>A[0][1])
            swap(&A[0][0],&A[0][1]);
        if(A[0][2]>A[0][3])
            swap(&A[0][2],&A[0][3]);
        if(A[1][0]>A[1][1])
            swap(&A[1][0],&A[1][1]);
        if(A[1][2]>A[1][3])
            swap(&A[1][2],&A[1][3]);
        if(A[0][2]>=A[0][1]||A[0][3]<=A[0][0]||A[1][2]>=A[1][1]||A[1][3]<=A[1][0])
        printf("%d\n",0);
        else
        {
            bubbleSort(A[0]);
            bubbleSort(A[1]);
            s=fabs(A[0][1]-A[0][2])*fabs(A[1][1]-A[1][2]);
            printf("%d\n",s);
        }
    return 0;
}
