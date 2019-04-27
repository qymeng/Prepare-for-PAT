/* 1082 Éä»÷±ÈÈü */
#include <stdio.h>

int main()
{
    int noMax, noMin;
    int max, min;

    int N;
    scanf("%d", &N);

    int i;
    int x, y, no, distance;
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &no, &x, &y);
        distance = x * x + y * y;
        if (i == 0)
        {
            noMax = no;
            noMin = no;
            min = max = distance;
            continue;
        }
        if (distance < min)
        {
            noMin = no;
            min = distance;
            continue;
        }
        if (distance > max)
        {
            noMax = no;
            max = distance;
        }
    }

    printf("%04d %04d", noMin, noMax);

    return 0;
}
