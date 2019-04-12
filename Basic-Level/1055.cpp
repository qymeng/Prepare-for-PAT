/* 1055 集体照 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX_LEN 10

struct Person
{
    char name[MAX_LEN];
    int height;
};

bool comp(struct Person p1, struct Person p2)
{
    if (p1.height != p2.height)
    {
        return p1.height < p2.height;
    }
    return strcmp(p1.name, p2.name) > 0;
}

int main()
{
    int N, K;
    int i, j;
    int raw, len;

    //1.输入
    scanf("%d%d", &N, &K);

    struct Person *buffer = (struct Person *)malloc(N * sizeof(struct Person));
    for (i = 0; i < N; i++)
    {
        scanf("%s%d", buffer[i].name, &buffer[i].height);
    }

    //2.排队
    sort(buffer, buffer + N, comp);
    // for (i = 0; i < N; i++)
    // {
    //     printf("%s ", buffer[i].name);
    // }
    // printf("\n");

    raw = N / K;

    len = N % K + raw;
    int *order = (int *)malloc(len * sizeof(int));

    for (i = N - len; i >= 0; i -= len)
    {
        for (j = 0; j < len; j++)
        {
            order[len / 2 + (j % 2 == 0 ? (j + 1) / 2 : -(j + 1) / 2)] = i + len - 1 - j;
        }
        for (j = 0; j < len; j++)
        {
            printf("%s%s", buffer[order[j]].name, j == len - 1 ? "\n" : " ");
        }
        len = raw;
    }

    free(order);
    free(buffer);
    return 0;
}
