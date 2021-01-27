#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int icity = 0, icapital = 0, itemp = 0, i, j;
	int* pcharm, * pstatus;
	long long int lltotal = 0, lltotal_cap,  llcharmsum = 0, llcharmsum_cap = 0;
	scanf("%d%d", &icity, &icapital);
	pcharm = (int*)malloc(icity * sizeof(int));
	pstatus = (int*)malloc(icity * sizeof(int));
	memset(pstatus, 0, icity * sizeof(int));
	for (i = 0; i < icity; i++)
	{
		scanf("%d", &pcharm[i]);
		llcharmsum = llcharmsum + pcharm[i];
	}
	for (i = 0; i < icapital; i++)
	{
		scanf("%d", &itemp);
		pstatus[itemp - 1] = 1;
		llcharmsum_cap = llcharmsum_cap + pcharm[itemp - 1];
	}
	for (i = 0; i < icity; i++)
	{
		if (pstatus[i] == 1)
		{
			lltotal = lltotal + 2 * (llcharmsum - llcharmsum_cap) * pcharm[i];
			lltotal = lltotal + (llcharmsum_cap - pcharm[i]) * pcharm[i];
		}
		else
		{
			if (pstatus[(i - 1 + icity) % icity] == 0)
				lltotal = lltotal + pcharm[(i - 1 + icity) % icity] * pcharm[i];
			if (pstatus[(i + 1) % icity] == 0)
				lltotal = lltotal + pcharm[(i + 1) % icity] * pcharm[i];
		}
	}
	lltotal = lltotal / 2;
	printf("%lld", lltotal);
	free(pcharm);
	free(pstatus);
	return 0;
}
