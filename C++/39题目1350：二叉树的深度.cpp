
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct BinTreeNode {
	BinTreeNode(): lChild(NULL), rChild(NULL) {}

	BinTreeNode* lChild;
	BinTreeNode* rChild;
};

// calculate depth by postorder traversing
int GetBinTreeDepth_Postorder(BinTreeNode* root)
{
	if (!root) return 0;

	int ldep = GetBinTreeDepth_Postorder(root->lChild);
	int rdep = GetBinTreeDepth_Postorder(root->rChild);

	return 1 + (ldep > rdep? ldep: rdep);
}

void DestroyTree(BinTreeNode* root)
{
	if (!root) return ;

	if (root->lChild)
		DestroyTree(root->lChild);

	if (root->rChild)
		DestroyTree(root->rChild);

	delete root;
}

int main()
{
	int n;
	cin >> n;

	BinTreeNode* root = new BinTreeNode;
	queue<BinTreeNode*> que;
	que.push(root);

	BinTreeNode* pNode;
	// Build binary tree (linked storage)
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;

		if (//(l != -1 || r != -1) && // get a node pointer when it has children
			!que.empty())
		{
			pNode = que.front();
			que.pop();
		}
		
		if (l != -1)
		{
			pNode->lChild = new BinTreeNode;
			que.push(pNode->lChild);
		}

		if (r != -1)
		{
			pNode->rChild = new BinTreeNode;
			que.push(pNode->rChild);
		}
	}

	if (n > 0)
		cout << GetBinTreeDepth_Postorder(root) << '\n';
	else /// Cuation: special case when n = 0
		cout << "0\n";

	DestroyTree(root);

	//system("pause");
	return 0;
}