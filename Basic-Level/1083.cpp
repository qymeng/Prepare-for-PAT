/* 1083 是否存在相等的差 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N;
    scanf("%d", &N);

    int *count = (int *)malloc(N * sizeof(int));
    memset(count, 0, N * sizeof(int));

    int i, temp;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        count[abs(i + 1 - temp)]++;
    }

    for (i = N - 1; i >= 0; i--)
    {
        if (count[i] > 1)
        {
            printf("%d %d\n", i, count[i]);
        }
    }

    free(count);
    return 0;
}
