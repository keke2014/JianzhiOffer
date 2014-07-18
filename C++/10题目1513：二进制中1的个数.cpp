
#include <stdio.h>

int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		for (int i = 0; i < T; ++i)
		{
			int n;
			scanf("%d", &n);

			int cnt = 0;
			while (n)
			{
				++cnt;
				n = n&(n-1);
			}
			printf("%d\n", cnt);
		}
	}

	return 0;
}