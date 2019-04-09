/* 1049 数列的片段和 */
//!!!第i个元素两边的选取情况
#include <stdio.h>

int main()
{
    int N, i, j, k;
    double sum = 0, temp;

    //1.输入
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%lf", &temp);
        sum += temp * (i + 1) * (N - i); //*
    }

    printf("%.2f", sum);

    return 0;
}
