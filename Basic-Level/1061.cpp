/* 1061 判断题 */
#include <stdio.h>

#define MAX_N 100

int main()
{
    int N, M;
    int mark[MAX_N];
    int answer[MAX_N];

    //1.输入
    scanf("%d%d", &N, &M);

    int i, j, temp;
    for (i = 0; i < M; i++)
    {
        scanf("%d", mark + i);
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d", answer + i);
    }

    //2.计算输出
    for (i = 0; i < N; i++)
    {
        int total = 0;
        for (j = 0; j < M; j++)
        {
            scanf("%d", &temp);
            total += (temp == answer[j] ? mark[j] : 0);
        }
        printf("%d\n", total);
    }

    return 0;
}
