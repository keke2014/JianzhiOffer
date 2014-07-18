
#include <stdio.h>
//#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);

	long long limit = 1;
	while (N-- > 0)
		limit *= 10;

	for (int i = 1; i < limit; ++i)
		printf("%lld\n", i);
	
	//system("pause");
	return 0;
}