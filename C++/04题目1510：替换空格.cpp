
#include <stdio.h>

int main()
{
	char c;
	while (scanf("%c", &c) != EOF)
	{
		if (c == ' ')
			printf("%%20");
		else
			putchar(c);
	}

	return 0;
}