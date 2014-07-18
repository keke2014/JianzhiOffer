
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (cin >> str)
	{
		char htbl[26] = { 0 }; // simple hash table

		int len = static_cast<int>(str.size());
		for (int i = 0; i < len; ++i)
			++htbl[str[i]-'A'];

		int idx = -1;
		for (int i = 0; i < len; ++i)			
		{
			if (htbl[str[i]-'A'] == 1)
			{
				idx = i;
				break;
			}
		}
		cout << idx << '\n';
	}
}
