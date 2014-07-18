
#include <stdio.h>

unsigned fn_terminator(unsigned n)
{
	return 0;
}

unsigned fn_accumulator(unsigned n);

typedef unsigned (*Func)(unsigned);
Func arrFunc[2] = { &fn_accumulator, &fn_terminator };

unsigned fn_accumulator(unsigned n)
{
	return n + arrFunc[!(n-1)](n-1);
}

int main()
{
	unsigned n;
	while (scanf("%d", &n) != EOF)
		printf("%d\n", fn_accumulator(n));

	return 0;
}