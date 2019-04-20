/* 1066 Í¼Ïñ¹ýÂË */
#include <stdio.h>

int main()
{
    int M, N;
    int A, B;
    int color;
    int i, j;
    int temp;

    scanf("%d%d%d%d%d", &M, &N, &A, &B, &color);

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &temp);
            if (temp >= A && temp <= B)
            {
                printf("%s%03d", j == 0 ? "" : " ", color);
            }
            else
            {
                printf("%s%03d", j == 0 ? "" : " ", temp);
            }
        }
        printf("\n");
    }

    return 0;
}
