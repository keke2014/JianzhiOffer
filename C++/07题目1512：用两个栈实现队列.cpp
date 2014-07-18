
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class CQueue {
public:
	void Push(int val)
	{
		stkIn.push(val);
	}

	int Pop()
	{
		int ret = -1;
		if (!stkOut.empty())
		{
			ret = stkOut.top();
			stkOut.pop();
		}
		else if (!stkIn.empty())
		{
			while (!stkIn.empty())
			{
				stkOut.push(stkIn.top());
				stkIn.pop();
			}
			ret = stkOut.top();
			stkOut.pop();
		}

		return ret;
	}
	
private:
	stack<int> stkIn;
	stack<int> stkOut;
};

int main()
{
	int n;
	cin >> n;
	
	CQueue que;
	while (n-- > 0)
	{
		string oprt;
		cin >> oprt;
		if (oprt == "PUSH")
		{
			int num;
			cin >> num;
			que.Push(num);
		}
		else
			cout << que.Pop() << endl;
	}

	//system("pause");
	return 0;
}