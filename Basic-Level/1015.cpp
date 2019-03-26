/* 1015 德才论 */
/*
(1)Input: N(1~10^5)、L(>=60)、H(1~99)，均为整数
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_N 100000

struct Student
{
    int num;
    int de;
    int cai;
    int sum;
    int type;
};

bool comp(struct Student a, struct Student b)
{
    if (a.type != b.type)
    {
        return a.type < b.type;
    }
    else if (a.sum != b.sum)
    {
        return a.sum > b.sum;
    }
    else if (a.de != b.de)
    {
        return a.de > b.de;
    }
    else
    {
        return a.num < b.num;
    }
}

int main()
{
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);

    struct Student buffer[MAX_N];
    memset(buffer, 0, MAX_N * sizeof(struct Student));

    int M = N, i;
    for (i = 0; i < N; i++)
    {
        scanf("%d%d%d", &(buffer + i)->num, &(buffer + i)->de, &(buffer + i)->cai);
        (buffer + i)->sum = (buffer + i)->de + (buffer + i)->cai;

        if ((buffer + i)->de < L || (buffer + i)->cai < L)
        {
            (buffer + i)->type = 5;
            M--;
        }
        else if ((buffer + i)->de >= H && (buffer + i)->cai >= H)
        {
            (buffer + i)->type = 1;
        }
        else if ((buffer + i)->de >= H)
        {
            (buffer + i)->type = 2;
        }
        else if ((buffer + i)->de >= (buffer + i)->cai)
        {
            (buffer + i)->type = 3;
        }
        else
        {
            (buffer + i)->type = 4;
        }
    }

    sort(buffer, buffer + N, comp);

    printf("%d\n", M);
    for (i = 0; i < M; i++)
    {
        if ((buffer + i)->type != 5)
        {
            printf("%d %d %d\n", (buffer + i)->num, (buffer + i)->de, (buffer + i)->cai);
        }
    }

    return 0;
}
