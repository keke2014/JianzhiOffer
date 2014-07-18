
#include <stdio.h>

struct BinTreeNode {
	BinTreeNode(): lChild(0), rChild(0) {}

	int nValue;
	int lChild;
	int rChild;
};

// sequential structure binary tree
BinTreeNode* BuildBinTree(int nodeCnt)
{
	if (nodeCnt == 0) return NULL;

	BinTreeNode* root = new BinTreeNode[nodeCnt+1];
	root[0].nValue = nodeCnt; // nValue of index 0 for node count
	for (int i = 1; i <= nodeCnt; ++i)
		scanf("%d", &root[i].nValue);

	for (int i = 1; i <= nodeCnt; ++i)
	{
		char sz[2] = { 0 };
		scanf("%s", &sz); // use '%s' to eat blank space
		bool lc = false;
		bool rc = false;
		switch (sz[0])
		{
		case 'd': lc = true; rc = true; break;
		case 'l': lc = true; break;
		case 'r': rc = true; break;
		}
		if (lc)
			scanf("%d", &root[i].lChild);
		if (rc)
			scanf("%d", &root[i].rChild);
	}

	return root;
}

// preorder traverse (recursive)
void PreorderSeq(BinTreeNode* root, int label, int* pOutCnt)
{
	if (root == NULL)
	{
		printf("NULL"); // empty bitree
		return ;
	}

	printf("%d", root[label].nValue);
	if (++*pOutCnt != root[0].nValue)
		putchar(' ');

	if (root[label].lChild)
		PreorderSeq(root, root[label].lChild, pOutCnt);

	if (root[label].rChild)
		PreorderSeq(root, root[label].rChild, pOutCnt);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		BinTreeNode* root = BuildBinTree(n);
		
		// calculate binary tree mirror
		for (int i = 1; i <= n; ++i)
		{
			int label = root[i].lChild;
			root[i].lChild = root[i].rChild;
			root[i].rChild = label;
		}

		int outCnt = 0;
		PreorderSeq(root, 1, &outCnt);
		printf("\n");
		
		delete [] root;
	}

	return 0;
}
