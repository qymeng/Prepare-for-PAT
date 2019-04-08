/* 1047 编程团体赛 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define SIZE 20

int main()
{
    int total[MAX_N] = {0};
    char buffer[SIZE];
    int team, score, N, i, champion, max, useless;

    //1.输入
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%s%d", buffer, &score);
        sscanf(buffer, "%d-%d", &team, &useless);

        total[team - 1] += score;
    }

    //2.输出
    for (i = 1, champion = 0, max = total[0]; i < MAX_N; i++)
    {
        if (total[i] > max)
        {
            max = total[i];
            champion = i;
        }
    }

    printf("%d %d", champion + 1, max);

    return 0;
}
