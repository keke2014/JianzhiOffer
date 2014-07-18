
#include <stdio.h>

int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		int** mat = new int*[m];
		for (int i = 0; i < m; ++i)
		{
			mat[i] = new int[n];
			for (int j = 0; j < n; ++j)
				scanf("%d", &mat[i][j]);
		}

		for (int start = 0; m > start*2 && n > start*2; ++start)
		{
			int endX = n-1-start;
			int endY = m-1-start;

			// left to right (alway exist)
			for (int x = start; x <= endX; ++x)
				printf("%d ", mat[start][x]);

			// up to down (at least two rows)
			if (start < endY)
			{
				for (int y = start+1; y <= endY; ++y)
					printf("%d ", mat[y][endX]);
			}

			// right to left 
			// (at least two rows and two columns)
			if (start < endY && start < endX)
			{
				for (int x = endX-1; x >= start; --x)
					printf("%d ", mat[endY][x]);
			}

			// down to up
			// (at least three rows and two columns)
			if (start+1 < endY && start < endX)
			{
				for (int y = endY-1; y >= start+1; --y)
					printf("%d ", mat[y][start]);
			}
		}
		//if (m && n)
			printf("\n");

		for (int i = 0; i < m; ++i)
			delete [] mat[i];
		delete [] mat;
	}

	return 0;
}