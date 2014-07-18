
#include <stdio.h>

// parallel stack
class CStack {
public:
	CStack(int len)
	{
		nums = new int[len];
		mins = new int[len];
		top = 0;
	}
	~CStack()
	{
		delete [] nums;
		delete [] mins;
	}

	void Push(int val)
	{
		nums[top++] = val;

		if (top == 1)
			mins[top-1] = val;
		else
		{
			int min = mins[top-2];
			if (val < min) min = val;		
			mins[top-1] = min;
		}
	}

	int Top()
	{
		return nums[top-1];
	}

	void Pop()
	{
		if (top >= 1) --top;
	}

	bool IsEmpty()
	{
		return top == 0;
	}

	int Min()
	{
		return mins[top-1];
	}

private:
	int* nums;
	int top;
	int* mins;
};

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		CStack stk(n);
		
		while (n--)
		{
			char oprt[2] = { 0 };
			scanf("%s", oprt);
			if (oprt[0] == 's')
			{
				int val;
				scanf("%d", &val);
				stk.Push(val);
			}
			else
				stk.Pop();

			if (stk.IsEmpty())
				printf("NULL\n");
			else
				printf("%d\n", stk.Min());
		}
	}
}