/* 1030 �������� */
//!!!Ҳ���α������Ŀ
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int main()
{
    int N, p, i, j, result;
    int buffer[MAX_N];

    //1.����
    scanf("%d%d", &N, &p);

    for (i = 0; i < N; i++)
    {
        scanf("%d", buffer + i);
    }

    //2.����
    sort(buffer, buffer + N);

    //3.ѭ������
    for (i = 0, j = 0, result = 0; i < N && j < N; i++) //��ѭ������m
    {
        while (j < N && buffer[j] <= (long long)buffer[i] * p) //��ѭ���̶�m����M
        {
            j++;
        }
        result = j - i > result ? j - i : result;
    }

    //4.���
    printf("%d", result);

    return 0;
}
