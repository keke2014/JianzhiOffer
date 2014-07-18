
#include <stdio.h>

// use merge sort to calculate inversed pairs
/// Caution: (10^5/2)*(10^5/2) = 25ÒÚ£¬2^32 = 4294967296
/// int: -4294967296/2~4294967296/2-1
/// unsigned: 0~4294967296-1
long long Inversions_MergeSort(int* nums, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = nums[start];
		return 0;
	}

	int half = (end-start)/2;
	long long left = Inversions_MergeSort(copy, nums, start, start+half);
	long long right = Inversions_MergeSort(copy, nums, start+half+1, end);

	long long cnt = 0;
	int i = start+half; // end of left part
	int j = end; // end of right part
	int copyIdx = end;
	while (i >= start && j >= start+half+1)
	{
		if (nums[i] > nums[j])
		{
			copy[copyIdx--] = nums[i--]; // bigger numbers come first
			cnt += j - (start+half+1) + 1; // numbers smaller than nums[i]
		}
		else
			copy[copyIdx--] = nums[j--];
	}

	// just copy the remaining numbers
	while (i >= start)
		copy[copyIdx--] = nums[i--];
	while (j >= start+half+1)
		copy[copyIdx--] = nums[j--];

	return left+right+cnt;
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int* nums = new int[n];
		int* copy = new int[n];

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &nums[i]);
			copy[i] = nums[i];
		}

		// time complex: O(nlogn)
		printf("%lld\n", Inversions_MergeSort(nums, copy, 0, n-1));
		delete [] nums;
		delete [] copy;
	}

	return 0;
}