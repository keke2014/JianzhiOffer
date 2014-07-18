
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void FillVector(vector<int>& vecNums, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		vecNums.push_back(num);
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> vecPushSeq, vecPopSeq;
		FillVector(vecPushSeq, n);
		FillVector(vecPopSeq, n);

		stack<int> stk;
		int i, j;
		for (i = 0, j = 0; i < n && j < n;)
		{
			if (!stk.empty() && stk.top() == vecPopSeq[j])
			{
				stk.pop();
				++j;
			}
			else if (vecPushSeq[i] == vecPopSeq[j])
			{
				++i;
				++j;
			}
			else
				stk.push(vecPushSeq[i++]);
		}

		bool bYes = true;
		while (bYes && !stk.empty())
		{
			if (stk.top() != vecPopSeq[j])
				bYes = false;
			else
			{
				stk.pop();
				++j;
			}
		}

		cout << (bYes? "Yes": "No") << endl;
	}

	return 0;
}