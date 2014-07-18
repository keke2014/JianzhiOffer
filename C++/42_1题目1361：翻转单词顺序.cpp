
#include <stdio.h>

const int LEN = 50002;

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
	char sntnc[LEN];
	while (gets(sntnc))
	{
		char* szStart = sntnc;

		char* szEnd = sntnc;
		while (*szEnd != '\0')
			++szEnd;
		--szEnd;

		// swap the whole sentence
		StrReverse(szStart, szEnd);

		szStart = szEnd = sntnc;
		while (*szStart != '\0')
		{
			if (*szStart == ' ')
			{
				++szStart;
				++szEnd;
			}
			else if (*szEnd == ' ' || *szEnd == '\0')
			{
				
				StrReverse(szStart, --szEnd); // swap one word
				szStart = ++szEnd;
			}
			else
				++szEnd;
		}

		puts(sntnc);
	}
}