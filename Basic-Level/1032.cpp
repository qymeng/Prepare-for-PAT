/* 1032 �ھ�������ļ�ǿ */
#include <stdio.h>

#define MAX_N 100000

int main()
{
    int N, i;
    int score[MAX_N + 1] = {0};
    int school, temp;
    int max, max_score;

    //1.����
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        scanf("%d%d", &school, &temp);
        score[school] += temp;
    }

    //2.ѭ��ȡֵ
    max = 0;
    max_score = score[0];
    for (i = 1; i <= MAX_N; i++)
    {
        if (score[i] > max_score)
        {
            max = i;
            max_score = score[i];
        }
    }

    //3.��ӡ
    printf("%d %d", max, max_score);

    return 0;
}
