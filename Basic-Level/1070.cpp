/* 1070 ���� */
//!!!ǰ�����������۰볤�Ȳ����ܴ�����һ��
#include <stdio.h>
#include <algorithm>
using namespace std;

#define BUFFER_SIZE 10000

int main()
{

    //1.����
    int N;
    scanf("%d", &N);

    int i;
    double buffer[BUFFER_SIZE];
    for (i = 0; i < N; i++)
    {
        scanf("%lf", buffer + i);
    }

    //2.��Լ
    sort(buffer, buffer + N);
    double result = buffer[0];
    for (i = 1; i < N; i++)
    {
        result = (result + buffer[i]) / 2;
    }

    //3.���
    printf("%d", (int)result);

    return 0;
}
