
#include <stdio.h>

struct ListNode {
	ListNode(): pNext(NULL) {}

	int nValue;
	ListNode* pNext;
};

// Build linked list
ListNode* BuildList(int nodeCnt)
{
	ListNode* head = NULL;

	ListNode** pHead = &head;
	for (int i = 0; i < nodeCnt; ++i)
	{
		*pHead = new ListNode;
		scanf("%d", &(*pHead)->nValue);
		pHead = &(*pHead)->pNext;
	}

	return head;
}

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
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		ListNode* head1 = BuildList(m);
		ListNode* head2 = BuildList(n);

		int diff = m-n;
		ListNode* pHeadLong = head1;
		ListNode* pHeadShort = head2;
		if (m < n)
		{
			diff = n-m;
			pHeadLong = head2;
			pHeadShort = head1;
		}

		// forward to the proper position
		for (int i = 0; i < diff; ++i)
			pHeadLong = pHeadLong->pNext;

		bool bFound = false;
		while (pHeadLong)
		{ // search for the first common node
			if (pHeadLong->nValue == pHeadShort->nValue)
			{
				bFound = true;
				break;
			}
			else
			{
				pHeadLong = pHeadLong->pNext;
				pHeadShort = pHeadShort->pNext;
			}
		}

		if (bFound)
			printf("%d\n", pHeadLong->nValue);
		else
			printf("My God\n");

		DestroyList(head1);
		DestroyList(head2);
	}

	return 0;
}