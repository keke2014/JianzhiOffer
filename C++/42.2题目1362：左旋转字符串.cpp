
#include <stdio.h>
#include <string.h>

const int LEN = 1001;

void StrReverse(char* szStart, char* szEnd)
{
	if (szStart == NULL || szEnd == NULL)
		return ;

	while (szStart < szEnd)
	{
		char c = *szStart;
		*szStart = *szEnd;
		*szEnd = c;

		++szStart;
		--szEnd;
	}
}

int main()
{
	char s[LEN];
	int k;
	while (scanf("%s %d", s, &k) != EOF)
	{
		unsigned len = strlen(s);
		k = k % len;

		if (k > 0)
		{
			char* szStart = s;

			char* szEnd = s;
			while (*szEnd != '\0')
				++szEnd;
			--szEnd;

			char* szMid = s;
			while (k--) ++szMid;

			StrReverse(szStart, szMid-1);
			StrReverse(szMid, szEnd);

			// swap the whole string
			StrReverse(szStart, szEnd);
		}

		puts(s);
	}
}