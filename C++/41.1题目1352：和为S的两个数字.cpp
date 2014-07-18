
#include <stdio.h>

struct Pair {
	// default is -1 (not found)
	Pair(): small(-1), big(-1) {}

	int small;
	int big;
};

int main()
{
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		int* nums = new int[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[i]);

		/// Cuation: n/2+1
		/// Test case: 2 1, 1
		Pair* pairs = new Pair[n/2+1];
		int pairCnt = 0;
		// approach from two sides
		for (int i = 0, j = n-1; i < j;)
		{
			if (nums[i]+nums[j] < k)
				++i;
			else if (nums[i]+nums[j] > k)
				--j;
			else
			{
				pairs[pairCnt].small = nums[i++];
				pairs[pairCnt].big = nums[j--];
				++pairCnt;
			}
		}

		int minIdx = 0;
		if (pairCnt > 1)
		{
			// Caution: use long long avoid overflow
			long long maxProd = (long long)pairs[0].small * pairs[0].big;
			for (int i = 1; i < pairCnt; ++i)
			{
				long long prod = (long long)pairs[0].small * pairs[0].big;
				if (prod > maxProd)
				{
					pairCnt = i;
					maxProd = prod;
				}
			}
		}

		printf("%d %d\n", pairs[minIdx].small, pairs[minIdx].big);
		delete [] nums;
		delete [] pairs;
	}
}