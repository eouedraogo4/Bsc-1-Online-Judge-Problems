#include <stdio.h>

#define N 32768  //N convert into binary is 1000 0000 0000 0000

int main()
{
    int  x, y;
    long int time;
    scanf("%ld", &time);
    for (long long int j = 0; j < time; j++)
    {
        int exist = 0;
        scanf("%d%d", &x, &y);
        for (int i = 0; i < 16; i++)
        {

            if (x==y)
            {
                exist = 1;
                break;
            }
            int tmp = N & x;

            if(tmp)
            {
                x=x^N;
                x=x<<1;
                x=x^1;
            }
            else
            {
                x=x<<1;
            }
        }
        if (exist)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
