
#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int* nums = new int[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", &nums[i]);

		int start = 0, end = n-1;
		while (start+1 < end) // one interval
		{
			int mid = (start+end)/2;

			if (nums[mid] == nums[start] &&
				nums[mid] == nums[end])
			{ // special case, use sequential search
				int min = nums[0];
				for (int i = 1; i < n; ++i)
				{
					if (nums[i] < min)
						min = nums[i];
				}
				printf("%d\n", min);
				end = -1;
				break;
			}
			
			if (nums[mid] >= nums[start] &&
				nums[mid] <= nums[end])
			{ // ordered
				end = start;
				break;
			}
			else if (nums[mid] >= nums[start]) // in right part
				start = mid;
			else if (nums[mid] <= nums[end]) // in left part
				end = mid;
		}

		if (end != -1)
			printf("%d\n", nums[end]);
		delete [] nums;
	}

	return 0;
}