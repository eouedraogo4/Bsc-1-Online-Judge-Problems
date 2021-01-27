#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k;
	int *array;
	scanf("%d%d", &n, &k);
	array = (int*)malloc(n*sizeof(int));
	scanf("%d", &array[0]);
	long long int sum = 0;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &array[i]);
		sum += array[i - 1] * array[i];
	}
	sum += array[n - 1] * array[0];

	for (int i = 0; i < k; i++)
	{
		int capital;
		scanf("%d", &capital);
		capital--;
		for (int j = 0; j < n; j++)
		{
			if (capital == 0 )
			{
				if ( j != n - 1 && j != capital && j!=capital+1)
				{
					sum += array[capital] * array[j];
				}

			}
			else if (capital == n - 1)
			{
				if (j != capital - 1 && j!=capital && j != 0 )
				{
					sum += array[capital] * array[j];
				}
			}
			else
			{
				if (j != capital - 1 && j != capital && j != capital + 1)
				{
					sum += array[capital] * array[j];
				}
			}
		}
		array[capital] = 0;
	}
	printf("%lld\n", sum);
	return 0;
}
