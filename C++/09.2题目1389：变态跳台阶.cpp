
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cout << static_cast<long>(pow(2.0f,n-1)) << endl;
	}

	return 0;
}