/* 1092 ��óԵ��±� */
//!!!�������ָ����ĳһ�������
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Mooncake
{
    int no;
    int total;
};

bool comp(struct Mooncake a, struct Mooncake b)
{
    if (a.total != b.total)
    {
        return a.total > b.total;
    }
    else
    {
        return a.no < b.no;
    }
}

int main()
{
    //1.����
    int N, M;
    scanf("%d %d", &N, &M);

    int i, j;
    struct Mooncake *buffer = (struct Mooncake *)malloc(N * sizeof(struct Mooncake));
    for (i = 0; i < N; i++)
    {
        buffer[i].no = i + 1;
        buffer[i].total = 0;
    }

    //2.ͳ��
    int temp;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &temp);
            buffer[j].total += temp;
        }
    }

    //3.�������
    sort(buffer, buffer + N, comp);
    int max = buffer[0].total;
    printf("%d\n", max);
    printf("%d", buffer[0].no);
    for (i = 1; i < N && buffer[i].total == max; i++)
    {
        printf(" %d", buffer[i].no);
    }

    //4.�ͷ�
    free(buffer);

    return 0;
}
