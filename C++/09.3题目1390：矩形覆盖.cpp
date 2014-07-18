
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long> vecFibo;
	vecFibo.push_back(1); // n = 1
	vecFibo.push_back(2); // n = 2

	int n;
	while (cin >> n)
	{
		if (vecFibo.size() < n)
		{
			for (int i = vecFibo.size()-1; i < n-1; ++i)
				vecFibo.push_back(vecFibo[i-1]+vecFibo[i]);
		}
		cout << vecFibo[n-1] << endl;
	}

	return 0;
}