/* 1001 �����˲�������(3n+1)���� */
#include <stdio.h>

int main()
{
	int input, count = 0;
	scanf("%d", &input);

	while (input != 1)
	{
		if (input % 2 == 1)
		{
			input = input * 3 + 1;
		}
		input >>= 1;
		count++;
	}

	printf("%d", count);

	return 0;
}
