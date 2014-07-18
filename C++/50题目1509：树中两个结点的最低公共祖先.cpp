
#include <stdio.h>
//#include <stdlib.h>

struct BinTreeNode {
	BinTreeNode(): lChild(NULL), rChild(NULL) {}

	int nValue;
	BinTreeNode* lChild;
	BinTreeNode* rChild;
};

// build binary tree from preorder sequence (linked storage)
void BuildBinTreeFromPreorder(BinTreeNode** pRoot, int* pNodeCnt)
{
	int val;
	scanf("%d", &val);
	if (val)
	{
		*pRoot = new BinTreeNode;
		(*pRoot)->nValue = val;
		++*pNodeCnt;
	}
	else
		return ;

	BuildBinTreeFromPreorder(&(*pRoot)->lChild, pNodeCnt);
	BuildBinTreeFromPreorder(&(*pRoot)->rChild, pNodeCnt);
}

// depth first search a path
bool GetPath(BinTreeNode* root, int value, int path[])
{
	if (!root) return false;

	path[++path[0]] = root->nValue;
	if (root->nValue == value) return true;

	bool left = GetPath(root->lChild, value, path);
	if (left) return true;

	bool right = GetPath(root->rChild, value, path);

	if (!right) --path[0]; // search failed -- go back

	return right;
}

void DestroyBinTree(BinTreeNode* root)
{
	if (root)
	{
		DestroyBinTree(root->lChild);
		DestroyBinTree(root->rChild);
		delete root;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		BinTreeNode* root = NULL;
		int nodeCnt = 0;
		BuildBinTreeFromPreorder(&root, &nodeCnt);

		int m1, m2;
		scanf("%d %d", &m1, &m2);
		int* path1 = new int[nodeCnt+1];
		int* path2 = new int[nodeCnt+1];
		path1[0] = 0;
		path2[0] = 0;
		GetPath(root, m1, path1);
		GetPath(root, m2, path2);

		int minCnt = path1[0];
		if (path1[0] > path2[0])
			minCnt = path2[0];

		int lastCommNode = 0;
		for (int i = 1; i <= minCnt; ++i)
		{
			if (path1[i] == path2[i])
				lastCommNode = path1[i];
			else
				break;
		}

		if (lastCommNode)
			printf("%d\n", lastCommNode);
		else
			printf("My God\n");

		delete [] path1;
		delete [] path2;
		DestroyBinTree(root);
	}

	//system("pause");
	return 0;
}
