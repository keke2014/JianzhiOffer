
#include <stdio.h>

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
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
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

		if (k < 1 || k > n || head == NULL)
			printf("NULL\n");
		else
		{
			ListNode *pBehined, *pAhead;
			pBehined = pAhead = head;

			for (int i = 0; i < k-1; ++i)
				pAhead = pAhead->pNext;

			while (pAhead->pNext)
			{
				pBehined = pBehined->pNext;
				pAhead = pAhead->pNext;
			}

			printf("%d\n", pBehined->nValue);
		}

		DestroyList(head);
	}

	return 0;
}