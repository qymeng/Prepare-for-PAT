/* 1053 ס�������� */
#include <stdio.h>

int main()
{
    int N, D, K;
    double e;

    int i, j, count;
    int possible = 0;
    int free = 0;
    double temp;

    //1.����
    scanf("%d%lf%d", &N, &e, &D);

    //2.ͳ��
    for (i = 0; i < N; i++)
    {
        scanf("%d", &K);
        count = 0;

        for (j = 0; j < K; j++)
        {
            scanf("%lf", &temp);
            if (temp < e)
            {
                count++;
            }
        }

        if (count <= K / 2)
        {
        }
        else if (K > D)
        {
            free++;
        }
        else
        {
            possible++;
        }
    }

    printf("%.01lf%% %.01lf%%", (double)possible / N * 100, (double)free / N * 100);

    return 0;
}
