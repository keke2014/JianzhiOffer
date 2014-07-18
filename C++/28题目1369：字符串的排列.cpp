
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int LEN = 11;

int main()
{
	char s[LEN];
	while (fgets(s, LEN, stdin))
	{
		size_t len = strlen(s)-1; /// Caution: the rear '\n'
		sort(s, s+len); // keep output in alphabetic order

		fputs(s, stdout); // print the first permutation
		while (next_permutation(s, s+len)) // use STL alg
			fputs(s, stdout);
	}

	return 0;
}
