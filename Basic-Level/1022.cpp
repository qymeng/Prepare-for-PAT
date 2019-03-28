/* 1022 D进制的A+B */
#include <stdio.h>

#define SIZE 32

int main()
{
    int A, B, D;
    int result[SIZE] = {0};
    int sum, count = 0, i;

    //1.输入
    scanf("%d%d%d", &A, &B, &D);

    //2.输出
    sum = A + B;
    do
    {
        result[count++] = sum % D;
        sum /= D;
    } while (sum != 0);

    for (i = count - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }

    return 0;
}
