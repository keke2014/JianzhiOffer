
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// special compare function
bool MyCmp(const string& str1, const string& str2)
{
	string comb1 = str1 + str2;
	string comb2 = str2 + str1;

	if (comb1 < comb2)
		return true;
	else
		return false;
}

int main()
{
	int m;
	while (scanf("%d", &m) != EOF)
	{
		vector<string> vecStrs;
		for (int i = 0; i < m; ++i)
		{
			string str;
			cin >> str;
			vecStrs.push_back(str);
		}

		sort(vecStrs.begin(), vecStrs.end(), MyCmp);

		for (int i = 0; i < m; ++i)
			cout << vecStrs[i];
		putchar('\n');
	}

	return 0;
}