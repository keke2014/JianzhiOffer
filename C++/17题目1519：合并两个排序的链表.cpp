
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

void BuildList(ListNode** pHead, int len)
{
	for (int i = 0; i < len; ++i)
	{
		int val;
		scanf("%d", &val);

		*pHead = new ListNode; // change 'next pointer'
		(*pHead)->nValue = val;
		pHead = &(*pHead)->pNext; // point to 'next pointer'
	}
}

void PrintAndInc(ListNode** ppNode, int* pOutCnt, int totatLen)
{
	printf("%d", (*ppNode)->nValue);
	*ppNode = (*ppNode)->pNext; // change 'next pointer'

	++*pOutCnt;
	if (*pOutCnt != totatLen)
		putchar(' ');
}

int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		if (m == 0 && n == 0)
		{
			printf("NULL\n");
			continue;
		}

		ListNode* head1 = NULL;
		BuildList(&head1, m);

		ListNode* head2 = NULL;
		BuildList(&head2, n);
		
		ListNode* pNode1 = head1;
		ListNode* pNode2 = head2;
		int outCnt = 0;
		while (pNode1 && pNode2)
		{
			if (pNode1->nValue <= pNode2->nValue)
				PrintAndInc(&pNode1, &outCnt, m+n);
			else
				PrintAndInc(&pNode2, &outCnt, m+n);
		}

		while (pNode1)
			PrintAndInc(&pNode1, &outCnt, m+n);
		while (pNode2)
			PrintAndInc(&pNode2, &outCnt, m+n);

		putchar('\n');
		DestroyList(head1);
		DestroyList(head2);
	}

	return 0;
}