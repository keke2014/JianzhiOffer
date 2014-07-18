
#include <stdio.h>

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		int sum = 0;
		int carry;

		do
		{
			sum = m^n; // sum without carry
			carry = (m&n) << 1;

			m = sum;
			n = carry;
		}
		while (carry);

		printf("%d\n", sum);
	}
}