#include <stdio.h>

struct person
{
    char name[20] ;
    int year ;
    int month ;
    int day ;
    int idx ;
};
struct person person[100];
int n, m ;

void Ssort()
{
    for( int i=0; i<n-1; i++ )
    {
        int min = person[i].year ;
        struct person tmp = person[i] ;
        int loc = i ;
        for( int j=i+1; j<n; j++ )
            if(min > person[j].year)
            {
                min = person[j].year ;
                tmp = person[j] ;
                loc = j;
            }
        for( int j=loc; j>i; j-- )
            person[j] = person[j-1];
        person[i] = tmp ;
    }
}

void Ssort_idx(int start, int end)
{
    for( int i=start; i<end; i++ )
    {
        int min = person[i].idx ;
        struct person tmp = person[i] ;
        int loc = i ;
        for( int j=i+1; j<=end; j++ )
            if(min > person[j].idx)
            {
                min = person[j].idx ;
                tmp = person[j] ;
                loc=j;
            }
        for( int j=loc; j>i; j-- )
            person[j] = person[j-1];
        person[i] = tmp ;
    }
}

void reverse(int start, int end)
{
    int i=start,j=end;
    while(i<j)
    {
        struct person tmp = person[i] ;
        person[i] = person[j] ;
        person[j] = tmp ;
        i++ ; j-- ;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",person[i].name);
        scanf("%d",&person[i].year);
        scanf("%d",&person[i].month);
        scanf("%d",&person[i].day);
    }

    Ssort();

    for( int i=0; i<n; i++ )
        person[i].idx = person[i].month*31 + person[i].day ;
    for( int i=0; i<n; i++ )
        {
            int start = i ;
            while(i<n-1 && person[i].year == person[i+1].year )
                i++ ;
            int end = i;
            Ssort_idx(start, end) ;
        }

    for(int i=0; i<n; i++)
        {
            int start = i ;
            while( i<n-1 && person[i].day == person[i+1].day)
                i++ ;
            int end = i;
            reverse(start, end) ;
        }

    for(int i=0;i<n;i++)
        printf("%s\n",person[i].name);

    return 0;
}
