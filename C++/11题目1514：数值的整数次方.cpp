
#include <stdio.h>

int main()
{
	int T;
	while (scanf("%d", &T) != EOF)
	{
		for (int i = 0; i < T; ++i)
		{
			double base;
			int exp;
			scanf("%lf %d", &base, &exp);
			
			double ret = 1.0;
			bool recip = false;
			if (base == 0.0)
			{ // special cases
				if (exp == 0)
					printf("%.2ef\n", ret);
				else if (exp > 0)
					printf("%.2ef\n", 0.0);
				else
					printf("INF\n");
			}
			else
			{
				if (exp != 0)
				{
					if (exp < 0)
					{
						recip = true;
						exp = -exp;
					}

					for (int i = 0; i < exp; ++i)
						ret *= base;

					if (recip)
						ret = 1/ret;
				}

				printf("%.2ef\n", ret); // append an 'f'
			}
		}
	}

	return 0;
}