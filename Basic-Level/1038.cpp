/* 1038 统计同成绩学生 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 101

int main()
{
    int N, K, i, j, temp;
    int buffer[SIZE] = {0};

    //1.输入
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        buffer[temp]++;
    }

    scanf("%d", &K);
    for (i = 0; i < K; i++)
    {
        scanf("%d", &temp);
        if (i != K - 1)
        {
            printf("%d ", buffer[temp]);
        }
        else
        {
            printf("%d", buffer[temp]);
        }
    }

    return 0;
}
