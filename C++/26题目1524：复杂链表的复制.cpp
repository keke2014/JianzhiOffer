
#include <stdio.h>

struct ListNode {
	ListNode(): pNext(NULL), pSpec(NULL) {}

	int nValue;
	ListNode* pNext;
	ListNode* pSpec;
};

ListNode* BulidList(int nodeCnt)
{
	ListNode* head = NULL;

	ListNode** pHead = &head;
	for (int i = 0; i < nodeCnt; ++i)
	{ // construct list
		*pHead = new ListNode;
		scanf("%d", &(*pHead)->nValue);
		pHead = &(*pHead)->pNext;
	}

	ListNode* pNode = head;
	for (int i = 0; i < nodeCnt; ++i)
	{ // set special pointer of each node
		int label;
		scanf("%d", &label);
		if (label > 0)
		{
			ListNode* pTmp = head;
			for (int j = 1; j < label; ++j)
				pTmp = pTmp->pNext;
			pNode->pSpec = pTmp;
		}
		pNode = pNode->pNext;
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
	int n;
	while (scanf("%d", &n) != EOF)
	{
		ListNode* head = BulidList(n);

		ListNode* pNode = head;
		ListNode* pNodeCpy = NULL;
		while (pNode)
		{ // make a headCpy of each node
			pNodeCpy = new ListNode;
			pNodeCpy->nValue = pNode->nValue;
			pNodeCpy->pNext = pNode->pNext;
			pNode->pNext = pNodeCpy;
			pNode = pNodeCpy->pNext;
		}

		pNode = head;
		while (pNode)
		{ // set spcecial pointers of headCpy nodes
			pNodeCpy = pNode->pNext; // set when pNode isn't NULL

			if (pNode->pSpec) /// Caution: only set when not null
				pNodeCpy->pSpec = pNode->pSpec->pNext;
			pNode = pNodeCpy->pNext;
		}

		pNode = head;
		ListNode* headCpy = NULL;
		ListNode** pHeadCpy = &headCpy;
		while (pNode)
		{ // extract the copy list
			*pHeadCpy = pNode->pNext;
			pNode->pNext = (*pHeadCpy)->pNext;

			/// Caution: forward
			pNode = pNode->pNext;
			pHeadCpy = &(*pHeadCpy)->pNext;
		}

		pNodeCpy = headCpy;
		while (pNodeCpy)
		{ // traverse and print the copy list

			int nValSpec = 0;
			if (pNodeCpy->pSpec)  /// Caution: only get when not null
				nValSpec = pNodeCpy->pSpec->nValue;

			printf("%d %d\n", pNodeCpy->nValue, nValSpec);
			pNodeCpy = pNodeCpy->pNext;
		}

		DestroyList(head);
		DestroyList(headCpy);
	}

	return 0;
}