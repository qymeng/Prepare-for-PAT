/* 1056 ������ĺ� */
#include <stdio.h>

int main()
{
    int N, i;
    int sum = 0, temp;

    //1.����
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &temp);

        sum += temp * 11 * (N - 1);
    }

    //2.���
    printf("%d", sum);

    return 0;
}
