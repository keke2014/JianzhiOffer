
#include <stdio.h>

// binary search first k (time complex: O(logn))
int GetIndexOfFisrtK(int nums[], int len, int k)
{
	int start = 0;
	int end = len-1;
	while (start <= end)
	{
		int mid = (start+end)/2;
		if (nums[mid] > k)
			end = mid-1;
		else if (nums[mid] < k)
			start = mid+1;
		else
		{
			if (mid == 0 || nums[mid-1] != k)
				return mid;
			else
				end = mid-1;
		}
	}
	return -1;
}

// binary search last k (time complex: O(logn))
int GetIndexOfLastK(int nums[], int len, int k)
{
	int start = 0;
	int end = len-1;
	while (start <= end)
	{
		int mid = (start+end)/2;
		if (nums[mid] > k)
			end = mid-1;
		else if (nums[mid] < k)
			start = mid+1;
		else
		{
			if (mid == len-1 || nums[mid+1] != k)
				return mid;
			else
				start = mid+1;
		}
	}
	return -1;
}

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
			int firstIdx = GetIndexOfFisrtK(nums, n, k);
			if (firstIdx == -1)
				printf("0\n");
			else
				printf("%d\n", GetIndexOfLastK(nums, n, k)-firstIdx+1);
		}

		delete [] nums;
	}
}