/* 1008 数组元素循环右移问题 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, move;
    scanf("%d%d", &n, &move);
    move %= n;

    int *buffer = (int *)malloc(n * sizeof(int));
    int i, j;

    for (i = 0; i < n; i++)
    {
        scanf("%d", buffer + i);
    }

    for (i = 0; i < n; i++)
    {
        j = i - move;
        if (j < 0)
        {
            j += n;
        }
        if (j >= n)
        {
            j -= n;
        }

        printf("%d%s", buffer[j], (i == n - 1 ? "\n" : " "));
    }

    free(buffer);
    return 0;
}