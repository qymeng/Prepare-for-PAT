/* 1021 ��λ��ͳ�� */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
#define SIZE 10

int main()
{
    int buffer[SIZE] = {0};
    int i;
    char N[MAX_LEN] = "";

    //1.����
    scanf("%s", N);

    //2.����
    int len = strlen(N);
    for (i = 0; i < len; i++)
    {
        buffer[N[i] - '0']++;
    }

    //3.���
    for (i = 0; i < SIZE; i++)
    {
        if (buffer[i] != 0)
        {
            printf("%d:%d\n", i, buffer[i]);
        }
    }

    return 0;
}
