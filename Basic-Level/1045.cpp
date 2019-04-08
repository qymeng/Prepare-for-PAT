/* 1045 �������� */
//!!!��������Ԫ�ĸ���Ϊ0ʱ��Ҫ��ӡһ������
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int main()
{
    int N, i, min, max, temp, count;
    int buffer[MAX_N] = {0};
    int prob[MAX_N] = {0};
    bool status[MAX_N];

    //1.����
    scanf("%d", &N);

    //2.��ѡ
    max = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        if (temp > max)
        {
            status[i] = true;
            max = temp;
        }
        else
        {
            status[i] = false;
        }
        buffer[i] = temp;
    }

    min = buffer[N - 1];
    count = 0;
    if (status[N - 1])
    {
        prob[count++] = buffer[N - 1];
    }

    for (i = 1; i < N; i++)
    {
        int index = N - 1 - i;
        temp = buffer[index];
        if (temp < min)
        {
            min = temp;
        }
        else
        {
            continue;
        }
        if (status[index])
        {
            prob[count++] = temp;
        }
    }

    //3.����
    sort(prob, prob + count);

    //4.���
    printf("%d\n%s", count, count == 0 ? "\n" : "");

    for (i = 0; i < count; i++)
    {
        printf("%d%s", prob[i], i == count - 1 ? "" : " ");
    }

    return 0;
}
