
#include <stdio.h>

struct BinTreeNode {
	BinTreeNode(): lChild(NULL), rChild(NULL) {}

	int nValue;
	BinTreeNode* lChild;
	BinTreeNode* rChild;
};

bool BuildTree(int len, int preOrder[], int inOrder[], BinTreeNode** root)
{
	*root = new BinTreeNode;
	(*root)->nValue = preOrder[0];

	int pos = 0;
	while (pos < len)
	{
		if (inOrder[pos] == preOrder[0])
			break;
		++pos;
	}

	if (pos == len) return false;

	bool left = true, right = true;
	if (pos > 0)
		left = BuildTree(pos, preOrder+1, inOrder, &(*root)->lChild);

	if (pos < len-1)
		right = BuildTree(len-1-pos, preOrder+1+pos, inOrder+pos+1, &(*root)->rChild);

	return (left && right);
}

void PostOrderTraverse(BinTreeNode* root)
{
	if (root->lChild)
		PostOrderTraverse(root->lChild);

	if (root->rChild)
		PostOrderTraverse(root->rChild);

	printf("%d ", root->nValue);
}

void DestroyBinTree(BinTreeNode* root)
{
	if (!root) return ;

	if (root->lChild)
		DestroyBinTree(root->lChild);
	if (root->rChild)
		DestroyBinTree(root->rChild);

	delete root;
}

int main()
{
	int len;
	while (scanf("%d", &len) != EOF)
	{
		int* preOrder = new int[len];
		for (int i = 0; i < len; ++i)
			scanf("%d", &preOrder[i]);

		int* inOrder = new int[len];
		for (int i = 0; i < len; ++i)
			scanf("%d", &inOrder[i]);

		BinTreeNode* root = NULL;
		if (BuildTree(len, preOrder, inOrder, &root))
			PostOrderTraverse(root);
		else
			printf("No");
		printf("\n");

		DestroyBinTree(root);
		delete [] preOrder;
		delete [] inOrder;
	}

	return 0;
}