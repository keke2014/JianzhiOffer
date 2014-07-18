
#include <stdio.h>
#include <queue>
using namespace std;

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

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		BinTreeNode* root = BuildBinTree(n);

		// level traverse (use queue)
		queue<int> que;
		if (root) que.push(1);

		int outCnt = 0;
		while (!que.empty())
		{
			int label = que.front();
			printf("%d", root[label].nValue);
			if (++outCnt != n) putchar(' ');

			que.pop();
			if (root[label].lChild)
				que.push(root[label].lChild);
			if (root[label].rChild)
				que.push(root[label].rChild);
		}
		printf("\n");
		
		delete [] root;
	}

	return 0;
}
