
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		int* nums = new int[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[i]);

		sort(nums, nums+n);

		for (int i = 0; i < k-1; ++i)
			printf("%d ", nums[i]);
		printf("%d\n", nums[k-1]);

		delete [] nums;
	}

	return 0;
}
