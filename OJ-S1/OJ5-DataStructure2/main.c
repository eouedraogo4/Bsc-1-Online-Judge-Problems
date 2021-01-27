#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array,*check, n, m, count=0 ;
    scanf("%d",&n) ;
    array = malloc( n*sizeof(int) ) ;
    check = malloc( n*sizeof(int) ) ;

    for( int i=0; i<n; i++ )
    {
        scanf( "%d", &array[i] ) ;
        check[i] = 0 ;
    }

    scanf("%d",&m) ;

    printf("%d\n",n) ;
    for( int i=0; i<n ;i++ )
        printf("%d ",array[i]) ;

    for( int i=0; i<n ;i++ )
        if( array[i] != m )
            check[i] = 1 ;

    for( int i=0; i<n; i++)
        if(check[i])
            count++ ;
    printf("\n%d\n",count) ;

    for( int i=0; i<n; i++)
        if(check[i])
        printf("%d ",array[i]);
    return 0;
}
