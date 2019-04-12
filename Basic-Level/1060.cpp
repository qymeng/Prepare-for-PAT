/* 1060 爱丁顿数 */
//!!!倒着验证，第几天时没有超过，输出上一天
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 100000

bool comp(int a, int b)
{
    return a >= b;
}

int main()
{
    //1.输入
    int N;
    scanf("%d", &N);

    int i;
    int *buffer = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", buffer + i);
    }

    //2.排序
    sort(buffer, buffer + N, comp);

    for (i = 0; i < N; i++)
    {
        if (buffer[i] <= i + 1)
        {
            break;
        }
    }

    printf("%d", i);

    free(buffer);
    return 0;
}
