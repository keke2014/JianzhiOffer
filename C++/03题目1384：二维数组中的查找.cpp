
#include <stdio.h>

int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n) == 2)
	{
		int t;
		scanf("%d", &t);
		
		int i, j;
		int** mat = new int*[m];
		for (i = 0; i < m; ++i)
		{
			mat[i] = new int[n];
			for (j = 0; j < n; ++j)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		
		bool bFond = false;
		for (i = 0, j = n-1; i < m && j >= 0;)
		{
			if (mat[i][j] > t)
				--j;
			else if (mat[i][j] < t)
				++i;
			else
			{
				bFond = true;
				break;
			}
		}
		
		printf("%s\n", bFond? "Yes": "No");
		for (int i = 0; i < m; ++i)
            delete [] mat[i];
        delete [] mat;
	}

	return 0;
}