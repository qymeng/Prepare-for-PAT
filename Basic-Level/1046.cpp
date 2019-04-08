/* 1046 ªÆ»≠ */
#include <stdio.h>
int main()
{
    int N;
    int a, b, sumA, sumB;
    int i;
    int countA = 0;
    int countB = 0;

    //1. ‰»Î
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d%d%d%d", &a, &sumA, &b, &sumB);
        if (a + b == sumA && a + b == sumB)
        {
        }
        else if (a + b == sumA)
        {
            countB++;
        }
        else if (a + b == sumB)
        {
            countA++;
        }
    }

    //2. ‰≥ˆ
    printf("%d %d", countA, countB);

    return 0;
}
