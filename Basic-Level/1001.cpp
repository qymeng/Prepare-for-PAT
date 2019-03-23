#include <stdio.h>
int main()
{
	int n, step = 0;
	scanf("%d", &n);
	
	while(n!=1)
	{
		if(n % 2 == 1)
		{
			n = n * 3 + 1;
		}
		n >>= 1;
		
		step++;
	}

	printf("%d", step);
	
	return 0;
}
