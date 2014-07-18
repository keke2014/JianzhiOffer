
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;

		vector<int> vecPoker;
		int zeroCnt = 0;
		for (int i = 0; i < n; ++i)
		{
			int poker;
			cin >> poker;
			if (poker == 0) // accumulate '0'
				++zeroCnt;
			else
				vecPoker.push_back(poker);
		}

		sort(vecPoker.begin(), vecPoker.end());
		
		int pokerCnt = static_cast<int>(vecPoker.size());
		bool bRepeat = false;
		int gapCnt = 0;
		for (int i = 0; i < pokerCnt-1; ++i)
		{
			if (vecPoker[i] == vecPoker[i+1])
			{ // detect repeation
				bRepeat = true;
				break;
			}
			else
				gapCnt += vecPoker[i+1]-vecPoker[i]-1;
		}

		if (bRepeat || gapCnt > zeroCnt) // check
			cout << "Oh My God!\n";
		else
			cout << "So Lucky!\n";
	}
}