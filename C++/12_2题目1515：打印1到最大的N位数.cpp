
#include <stdio.h>
//#include <stdlib.h>

void PrintNums(char nums[], int len, int idx)
{
	if (idx == len-1)
	{
		int start = 0;
		// jump over leading zeroes
		while (start < len && nums[start] == '0')
			++start;

		if (start < len) // no output for all zeroes
			printf("%s\n", nums+start);
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{ // set next bit
			nums[idx+1] = i+'0'; // init
			PrintNums(nums, len, idx+1);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	char* nums = new char[N+1];
	nums[N] = '\0';

	for (int i = 0; i < 10; ++i)
	{ // start from MSB
		nums[0] = i+'0'; // init
		PrintNums(nums, N, 0);
	}
	
	//system("pause");
	return 0;
}