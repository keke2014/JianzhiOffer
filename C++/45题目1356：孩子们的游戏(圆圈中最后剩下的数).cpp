
#include <cstdio>
#include <iostream>
using namespace std;

// Joseph circle problem
int main()
{
	int n, m;
	while (cin >> n)
	{
		if (n == 0) break;
		cin >> m;

		// 0 ~ n-1
		int last = 0; // n = 1
		for (int i = 2; i <= n; ++i)
			last = (last+m) % i; // n > 1

		printf("%d\n", last+1);
	}
}