
#include <stdio.h>
//#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int len = 0;
	int* nums = new int[n];
	int outCnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int num;
		scanf("%d", &num);
		if (num%2 == 0)
			nums[len++] = num;
		else
		{
			printf("%d", num);
			++outCnt;
			if (outCnt != n)
				putchar(' ');
		}
	}
	for (int i = 0; i < len; ++i)
	{
		printf("%d", nums[i]);
		if (i != len-1)
				putchar(' ');
	}
	putchar('\n');
	delete [] nums;
		
	//system("pause");
	return 0;
}