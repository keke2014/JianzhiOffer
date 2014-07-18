
#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0) break;

		int maxSum, maxStart, maxEnd;
		// always init maxSum to be the first value,
		// may be negative (still work)
		scanf("%d", &maxSum);
		maxStart = maxEnd = 0;

		int curSum = maxSum, curStart = 0;
		if (curSum < 0)
		{ // move to the next when the first value is positive
			curSum = 0;
			curStart = 1;
		}

		int num;
		for (int i = 1; i < n; ++i)
		{
			scanf("%d", &num);
			curSum += num;

			if (curSum > maxSum)
			{ // always compare (even if negative)
				maxSum = curSum;
				maxStart = curStart;
				maxEnd = i;
			}

			if (curSum < 0)
			{ // move to the next when the curSum is positive
				curSum = 0;
				curStart = i+1;
			}
		}

		printf("%d %d %d\n", maxSum, maxStart, maxEnd);
	}

	return 0;
}