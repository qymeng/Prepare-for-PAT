/* 1064 ≈Û”— ˝ */
#include <stdio.h>

#define BUFFER_SIZE 10000
#define RADIX 10

int main()
{

    //1. ‰»Î
    int N;
    scanf("%d", &N);

    int i, temp;
    bool flag[BUFFER_SIZE] = {0};
    int sum;
    for (i = 0; i < N; i++)
    {
        sum = 0;
        scanf("%d", &temp);
        while (temp != 0)
        {
            sum += temp % RADIX;
            temp /= RADIX;
        }
        flag[sum - 1] = true;
    }

    for (sum = 0, i = 0; i < BUFFER_SIZE; i++)
    {
        if (flag[i])
        {
            sum++;
        }
    }

    printf("%d\n", sum);

    int count = 0;
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        if (flag[i])
        {
            count++;
            printf("%s%d", count == 1 ? "" : " ", i + 1);
        }
    }

    return 0;
}
