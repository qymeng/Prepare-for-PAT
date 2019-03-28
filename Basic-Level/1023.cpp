/* 1023 组个最小数 */
#include <stdio.h>

#define SIZE 10

int main()
{
    int buffer[SIZE] = {0};
    int i, j;

    //1.输入
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", buffer + i);
    }

    //2.打印
    for (i = 1; i < SIZE; i++)
    {
        if (buffer[i] != 0)
        {
            printf("%d", i);
            buffer[i]--;
            break;
        }
    }

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < buffer[i]; j++)
        {
            printf("%d", i);
        }
    }

    return 0;
}
