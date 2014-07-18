
#include <stdio.h>

// classify nums according first 1
bool IsKthBit1(int num, int k)
{
	return num & (1<<k);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int* nums = new int[n];
		// xorSum is just the two nums' (occuring once) exclusive or sum
		int xorSum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &nums[i]);
			xorSum ^= nums[i];
		}

		int k = 0;
		while (xorSum)
		{ // find first 1's postion (right most is 0)
			xorSum >>= 1;
			if (xorSum) ++k;
		}

		int xorSum1 = 0; // one
		int xorSum2 = 0; // the other
		for (int i = 0; i < n; ++i)
		{
			if (IsKthBit1(nums[i], k))
				xorSum1 ^= nums[i];
			else
				xorSum2 ^= nums[i];
		}

		int min = xorSum1;
		int max = xorSum2;
		if (xorSum1 > xorSum2)
		{
			min = xorSum2;
			max = xorSum1;
		}

		printf("%d %d\n", min, max);
		delete [] nums;
	}
}