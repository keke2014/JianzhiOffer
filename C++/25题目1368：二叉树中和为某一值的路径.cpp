
#include <stdio.h>
#include <math.h>

struct BinTreeNode {
	BinTreeNode(): lChild(-1), rChild(-1) {}

	int nValue;
	int lChild;
	int rChild;
};

// sequential structure binary tree
BinTreeNode* BuildBinTree(int nodeCnt)
{
	if (nodeCnt < 1) return NULL;

	BinTreeNode* root = new BinTreeNode[nodeCnt+1];
	root[0].nValue = nodeCnt; // nValue of index 0 for node count

	for (int i = 1; i <= nodeCnt; ++i) // '-1' stands for no [l|r]Child
		scanf("%d %d %d", &root[i].nValue, &root[i].lChild, &root[i].rChild);

	return root;
}

// deep fisrt search and print specific paths
void DFS(BinTreeNode* root, int trgt, int label, int* path, int* pSum)
{
	path[++path[0]] = label;
	*pSum += root[label].nValue;

	if (root[label].lChild == -1 &&
		root[label].rChild == -1 &&
		*pSum == trgt)
	{
		printf("A path is found: ");
		for (int i = 1; i <= path[0]; ++i)
		{
			printf("%d", path[i]);
			if (i < path[0]) putchar(' ');
		}
		putchar('\n');
	}

	// output in lexicographic order
	int min, max;
	if (root[label].lChild < root[label].rChild)
	{
		min = root[label].lChild;
		max = root[label].rChild;
	}
	else
	{
		min = root[label].rChild;
		max = root[label].lChild;
	}

	if (min != -1)
		DFS(root, trgt, min, path, pSum);

	if (max != -1)
		DFS(root, trgt, max, path, pSum);

	// roll back
	--path[0];
	*pSum -= root[label].nValue;
}

int main()
{
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF)
	{
		BinTreeNode* root = BuildBinTree(n);

		printf("result:\n");
		//int* path = new int[static_cast<int>(log((float)n)+1+2)];
		int* path = new int[n+1]; /// Todo: calculate bitree height
		path[0] = 0;
		int sum = 0;
		DFS(root, k, 1, path, &sum);

		delete [] root;
		delete [] path;
	}

	return 0;
}