
#include <stdio.h>
#include <set>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		multiset<int> setNums;
		int cnt = 0;
		int num;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			scanf("%d", &tmp);

			setNums.insert(tmp);

			if (cnt == 0)
			{
				num = tmp;
				cnt = 1;
			}
			else
			{
				if (tmp == num)
					++cnt;
				else
					--cnt;
			}
		}

		if (cnt == 0)
			printf("-1\n");
		else
		{ // only when cnt > 0 can num meet the condition
			if (setNums.count(num) > n/2)
				printf("%d\n", num);
			else
				printf("-1\n");
		}
	}

	return 0;
}