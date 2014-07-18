
#include <stdio.h>

// binary search tree postorder sequence check
bool IsBSTPostorderSeq(int nodes[], int nodeCnt)
{
	if (nodeCnt <= 2) // two or one node always be true
		return true;

	int rootIdx = nodeCnt-1; // the last is root

	int leftEnd = -1;
	for (int i = 0; i < rootIdx; ++i)
	{ // find the end of the left (if exist)
		if (nodes[i] < nodes[rootIdx])
			++leftEnd;
		else
			break;
	}

	int rightStart = rootIdx;
	for (int j = rootIdx-1; j >= 0; --j)
	{ // find the end of the right (if exist)
		if (nodes[j] > nodes[rootIdx])
			--rightStart;
		else
			break;
	}

	if (leftEnd+1 != rightStart) // disorder check
		return false;

	bool left = true;
	if (leftEnd > -1) // recursively check left subtree (if exist)
		left = IsBSTPostorderSeq(nodes, rightStart);

	bool right = true;
	if (rightStart < rootIdx) // recursively check right subtree (if exist)
		right = IsBSTPostorderSeq(nodes+rightStart, nodeCnt-rightStart-1);

	return (left&&right);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int* nodes = new int[n];
		for (int i = 0; i < n; ++i)
			scanf("%d", &nodes[i]);

		bool bYes = IsBSTPostorderSeq(nodes, n);
		printf("%s\n", bYes? "Yes": "No");
		delete [] nodes;
	}

	return 0;
}