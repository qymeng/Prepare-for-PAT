/* 1094 谷歌的招聘 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1001
#define BUFFER_SIZE 11

bool isPrime(int number)
{
    if (number == 0 || number == 1)
    {
        return false;
    }
    if (number == 2)
    {
        return true;
    }
    int temp = sqrt(number);
    for (int i = 2; i <= temp; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //1.输入参数
    int L, K;
    scanf("%d %d", &L, &K);

    char buffer[MAX_LEN];
    scanf("%s", buffer);

    //2.遍历
    int len = strlen(buffer);
    int i;
    char temp[BUFFER_SIZE];
    int number;
    for (i = 0; i + K - 1 < len; i++)
    {
        strncpy(temp, buffer + i, K);
        temp[K] = '\0';
        number = atoi(temp);
        if (isPrime(number))
        {
            printf("%s\n", temp);
            return 0;
        }
    }

    printf("404\n");

    return 0;
}
