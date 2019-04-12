/* 1056 组合数的和 */
#include <stdio.h>

int main()
{
    int N, i;
    int sum = 0, temp;

    //1.输入
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &temp);

        sum += temp * 11 * (N - 1);
    }

    //2.输出
    printf("%d", sum);

    return 0;
}
