/* 1049 ���е�Ƭ�κ� */
//!!!��i��Ԫ�����ߵ�ѡȡ���
#include <stdio.h>

int main()
{
    int N, i, j, k;
    double sum = 0, temp;

    //1.����
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%lf", &temp);
        sum += temp * (i + 1) * (N - i); //*
    }

    printf("%.2f", sum);

    return 0;
}
