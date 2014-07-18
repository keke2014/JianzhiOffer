
#include <stdio.h>

bool g_bInvalidArg;

int Str2int(char* str)
{
	g_bInvalidArg = false;
	if (str == NULL || *str == '\0')
	{
		g_bInvalidArg = true;
		return 0;
	}

	bool bNeg = false;
	if (str[0] == '-')
		bNeg = true;

	if (str[0] == '-' || str[0] == '+')
		++str;

	if (*str == '\0')
	{
		g_bInvalidArg = true;
		return 0;
	}

	long long out = 0;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			g_bInvalidArg = true;
			return 0;
		}
		else
		{
			// must keep the sign (for underflow checking)
			out = out*10 + (*str-'0')*(bNeg? -1: 1);

			if ((!bNeg && out > 0x7FFFFFFF) ||
				(bNeg && out < (signed int)0x80000000))
			{ // over[under]flow check
				g_bInvalidArg = true;
				return 0;
			}

			++str;
		}
	}

	return static_cast<int>(out);
}

int main()
{
	char str[50]; // long enough to hold illegal numbers
	while (scanf("%s", str) != EOF) // must use scanf() instead of gets()
	{ // discard leading and rear blank spaces ??
		int out = Str2int(str);
		if (out == 0 && g_bInvalidArg)
			printf("My God\n");
		else
			printf("%d\n", out);
	}
}