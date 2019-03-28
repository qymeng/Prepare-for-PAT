/* 1021 个位数统计 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
#define SIZE 10

int main()
{
    int buffer[SIZE] = {0};
    int i;
    char N[MAX_LEN] = "";

    //1.输入
    scanf("%s", N);

    //2.解析
    int len = strlen(N);
    for (i = 0; i < len; i++)
    {
        buffer[N[i] - '0']++;
    }

    //3.输出
    for (i = 0; i < SIZE; i++)
    {
        if (buffer[i] != 0)
        {
            printf("%d:%d\n", i, buffer[i]);
        }
    }

    return 0;
}
