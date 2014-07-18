
#include <stdio.h>

int main()
{
	int s;
	while (scanf("%d", &s) != EOF)
	{
		if (s < 0) break;

		// always start from 1, 2
		int small = 1;
		int big = 2;
		int lowBound = s/2+1; /// Caution: stop as earlier as possible
		int outCnt = 0;
		while (small < lowBound && small < big)
		{ // small, big always ahead (never back)
			int partialSum = (small+big)*(big-small+1)/2;
			if (partialSum < s)
				++big;
			else if (partialSum > s)
				++small;
			else
			{
				++outCnt;
				for (int i = small; i < big; ++i)
					printf("%d ", i);
				printf("%d\n", big);

				++small;
				++big;
			}
		}

		if (outCnt == 0)
			printf("Pity!\n");
		printf("#\n");
	}

	return 0;
}