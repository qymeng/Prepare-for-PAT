/* 1062 最简分数 */
#include <stdio.h>

#define BUFFER_SIZE 20

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

// int gcd(int a, int b)
// {
//     return b == 0 ? a : gcd(b, a % b);
// }

int main()
{
    //1.输入
    char buffer[BUFFER_SIZE];

    int N1, M1;
    scanf("%s", buffer);
    sscanf(buffer, "%d/%d", &N1, &M1);

    int N2, M2;
    scanf("%s", buffer);
    sscanf(buffer, "%d/%d", &N2, &M2);

    int K;
    scanf("%d", &K);

    //2.计算
    int M = M1 * M2;
    int min = N1 * M2;
    int max = N2 * M1;
    if (min > max)
    {
        int temp = min;
        min = max;
        max = temp;
    }
    int temp = gcd(M1, M2);
    M /= temp;
    min /= temp;
    max /= temp;

    int multiple = M * K / gcd(M, K);
    temp = multiple / M;
    min *= temp;
    max *= temp;
    temp = multiple / K;
    int count = 0;

    for (int i = min + 1; i < max; i++)
    {
        if (i % temp == 0)
        {
            if (gcd(i / temp, K) <= 1)
            {
                count++;
                printf("%s%d/%d", count == 1 ? "" : " ", i / temp, K);
            }
        }
    }

    return 0;
}
