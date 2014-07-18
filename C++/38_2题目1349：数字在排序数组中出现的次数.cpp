
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int* nums = new int[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[i]);

		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
		{
			int k;
			scanf("%d", &k);
			
			pair<int*, int*> bound;
			bound = equal_range(nums, nums+n, k);
			cout << distance(bound.first, bound.second) << '\n';
		}

		delete [] nums;
	}
}