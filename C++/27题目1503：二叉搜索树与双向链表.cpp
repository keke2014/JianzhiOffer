
#include <stdio.h>

struct BinTreeNode {
	BinTreeNode(): lChild(NULL), rChild(NULL) {}

	int nValue;
	BinTreeNode* lChild;
	BinTreeNode* rChild;
};

// construct linked binary tree from preorder sequence (recursively)
void BuildBinTreeFromPreorder(BinTreeNode** pRoot)
{
	int val;
	scanf("%d", &val);
	if (val)
	{
		*pRoot = new BinTreeNode;
		(*pRoot)->nValue = val;
		BuildBinTreeFromPreorder(&(*pRoot)->lChild);
		BuildBinTreeFromPreorder(&(*pRoot)->rChild);
	}
}

// convert binary tree to double linked list inplace
void BinTree2DblLinkList(BinTreeNode* root, BinTreeNode** ppLastNode)
{
	if (!root) return ;

	if (root->lChild)
		BinTree2DblLinkList(root->lChild, ppLastNode);

	if (*ppLastNode) /// Caution: may be NULL (first node)
	{
		root->lChild = *ppLastNode;
		(*ppLastNode)->rChild = root;
	}
	*ppLastNode = root;

	if (root->rChild)
		BinTree2DblLinkList(root->rChild, ppLastNode);
}

void DestroyList(BinTreeNode* head)
{
	while (head)
	{
		BinTreeNode* pNode = head;
		head = head->rChild;
		delete pNode;
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			BinTreeNode* root = NULL;
			BuildBinTreeFromPreorder(&root);

			BinTreeNode* pLastNode = NULL;
			BinTree2DblLinkList(root, &pLastNode);

			BinTreeNode* head = NULL;
			while (pLastNode)
			{ // back to the head
				head = pLastNode;
				pLastNode = pLastNode->lChild;
			}

			BinTreeNode* pNode = head;
			while (pNode)
			{ // print the list
				printf("%d ", pNode->nValue);
				pNode = pNode->rChild;
				/*if (pNode)
					putchar(' ');*/
			}
			if (head) putchar('\n');
			DestroyList(head);
		}
	}

	return 0;
}