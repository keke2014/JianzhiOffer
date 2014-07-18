
#include <stdio.h>
#include <stack>
using namespace std;

int main()
{
	stack<int> stk;
	int node;

	while (1)
	{
		scanf("%d", &node);

		if (node == -1)
			break;

		stk.push(node);
	}

	while (!stk.empty())
	{
		printf("%d\n", stk.top());
		stk.pop();
	}

	//system("pause");
	return 0;
}