/* 1024 科学计数法 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

int main()
{
    char A[MAX_LEN] = "";
    int decimalBits, index, i;

    //1.输入
    scanf("%s", A);

    //2.解析
    //(1)判断正负号
    if (A[0] == '-')
    {
        printf("-");
    }

    //(2)计算精度
    int len = strlen(A);
    for (i = 3, decimalBits = 0; A[i] != 'E'; i++)
    {
        decimalBits++;
    }

    //(3)获取指数
    index = atoi(A + i + 1);
    if (index >= 0)
    {
        if (index >= decimalBits)
        {
            printf("%c", A[1]);
            for (i = 3; A[i] != 'E'; i++)
            {
                printf("%c", A[i]);
            }
            for (i = 0; i < index - decimalBits; i++)
            {
                printf("0");
            }
        }
        else
        {
            printf("%c", A[1]);
            for (i = 0; i < index; i++)
            {
                printf("%c", A[3 + i]);
            }
            printf(".");
            for (i += 3; A[i] != 'E'; i++)
            {
                printf("%c", A[i]);
            }
        }
    }
    else
    {
        printf("0.");
        for (i = 0; i < -index - 1; i++)
        {
            printf("0");
        }
        for (i = 1; A[i] != 'E'; i++)
        {
            if (A[i] != '.')
            {
                printf("%c", A[i]);
            }
        }
    }

    return 0;
}
