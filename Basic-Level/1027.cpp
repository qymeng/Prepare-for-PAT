/* 1027 打印沙漏 */
#include <stdio.h>

int main()
{
    int N, i, j, k;
    char ch;

    //1.输入
    scanf("%d %c", &N, &ch);

    //2.打印
    for (i = 1, N--; N >= 4 * i + 2; i++)
    {
        N -= 4 * i + 2;
    }

    //(1)打印图形
    for (j = i - 1; j >= 0; j--)
    {
        for (k = 0; k < i - j - 1; k++)
        {
            printf(" ");
        }
        for (k = 0; k < 2 * j + 1; k++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    for (j = 1; j < i; j++)
    {
        for (k = 0; k < i - j - 1; k++)
        {
            printf(" ");
        }
        for (k = 0; k < 2 * j + 1; k++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }

    //(2)打印剩余量
    printf("%d", N);

    return 0;
}
