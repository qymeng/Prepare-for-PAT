/* 1087 有多少不同的值 */
#include <stdio.h>

#define BUFFER_SIZE 15000

int main()
{
    int N;
    scanf("%d", &N);

    bool buffer[BUFFER_SIZE] = {0};
    int i, result;
    for (i = 1; i <= N; i++)
    {
        result = i / 2 + i / 3 + i / 5;
        buffer[result] = true;
    }

    result = 0;
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i])
        {
            result++;
        }
    }

    printf("%d", result);

    return 0;
}
