
#include <stdio.h>
#include <stack>
using namespace std;

struct ListNode {
	ListNode(): pNext(NULL) {}

	int nValue;
	ListNode* pNext;
};

void DestroyList(ListNode* head)
{
	while (head)
	{
		ListNode* pNode = head;
		head = head->pNext;
		delete pNode;
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		ListNode* head = NULL;
		
		ListNode** ppNode = &head;
		for (int i = 0; i < n; ++i)
		{
			int val;
			scanf("%d", &val);

			*ppNode = new ListNode;
			(*ppNode)->nValue = val;
			ppNode = &(*ppNode)->pNext;
		}

		if (n == 0)
			printf("NULL\n");
		else
		{
			stack<int> stk;
			ListNode* pNode = head;
			while (pNode)
			{
				stk.push(pNode->nValue);
				pNode = pNode->pNext;
			}

			while (!stk.empty())
			{
				printf("%d", stk.top());
				stk.pop();
				if (!stk.empty())
					putchar(' ');
			}
			putchar('\n');
		}

		DestroyList(head);
	}

	return 0;
}