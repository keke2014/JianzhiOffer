
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
		int chldCnt;
		scanf("%d", &chldCnt);
		if (chldCnt >= 1)
			scanf("%d", &root[i].lChild);
		if (chldCnt > 1)
			scanf("%d", &root[i].rChild);
	}

	return root;
}

// preorder traverse
bool IsSubTree(BinTreeNode* root, int label,
			   BinTreeNode* rootSub, int labelSub)
{
	if (root[label].nValue != rootSub[labelSub].nValue)
		return false;

	bool left = true;
	if (rootSub[labelSub].lChild)
	{
		if (root[label].lChild == 0)
			left = false;
		else
			left = IsSubTree(root, root[label].lChild, rootSub, rootSub[labelSub].lChild);
	}
	
	bool right = true;
	if (rootSub[labelSub].rChild)
	{
		if (root[label].rChild == 0)
			right = false;
		else
			right = IsSubTree(root, root[label].rChild, rootSub, rootSub[labelSub].rChild);
	}

	return (left&&right);
}

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		BinTreeNode* root = BuildBinTree(n);
		BinTreeNode* rootSub = BuildBinTree(m);

		int bIsSubTree = false;
		if (n && m) /// Caution: n, m may be 0
		{
			// level traverse
			for (int i = 1; i <= n-m+1; ++i)
			{
				if (IsSubTree(root, i, rootSub, 1))
					bIsSubTree = true;
			}
		}
		printf("%s\n", bIsSubTree? "YES": "NO");
		
		delete [] root;
		delete [] rootSub;
	}

	return 0;
}