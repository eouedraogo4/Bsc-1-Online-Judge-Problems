#include <stdio.h>

int main()
{
    int  x, y, c;
    long long int time;
    scanf("%lld", &time);
    for (long long int j = 0; j < time; j++)
    {
        int exist = 0;
        scanf("%d%d%d", &x, &y, &c);
        for (int i = 0; i < 17; i++)
        {

            if (x==y)
            {
                exist = 1;
                break;
            }
            int tmp = c;
            c = 1 & x;
            x = x >> 1;
            if (tmp)
            {
                tmp = 32768;
                x = x ^ tmp;
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
