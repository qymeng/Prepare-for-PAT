/* 1040 有几个PAT */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100001
#define CONSTANT 1000000007

int main()
{
    char buffer[MAX_LEN];
    int sumP = 0;
    int sumA = 0;
    int sum = 0;
    int i;

    //1.输入
    scanf("%s", buffer);

    //2.计数
    int len = strlen(buffer);
    for (i = 0; i < len; i++)
    {
        char temp = buffer[i];
        if (temp == 'P')
        {
            sumP++;
        }
        else if (temp == 'A')
        {
            sumA += sumP;
        }
        else
        {
            sum += sumA;
            sum %= CONSTANT;
        }
    }

    printf("%d", sum);

    return 0;
}
