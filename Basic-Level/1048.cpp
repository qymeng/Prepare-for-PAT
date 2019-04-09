/* 1048 数字加密 */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 101
#define RADIX 13

void encrypt(const char *A, const char *B, char *code)
{
    int i, index, a, b;
    int len = strlen(A);
    const char *num = "0123456789JQK";

    for (i = 0; i < len; i++)
    {
        index = len - 1 - i;
        a = A[index] - '0';
        b = B[index] - '0';
        if (i % 2 == 0) //奇数位
        {
            code[index] = num[(a + b) % RADIX];
        }
        else //偶数位
        {
            code[index] = num[b - a + (b < a ? 10 : 0)];
        }
    }
}

int main()
{
    char A[MAX_LEN];
    char B[MAX_LEN];
    char temp[MAX_LEN];
    char code[MAX_LEN];
    int lenA, lenB, i;

    //1.输入
    scanf("%s %s", A, B);

    //2.处理
    lenA = strlen(A);
    lenB = strlen(B);

    if (lenA > lenB)
    {
        for (i = 0; i < lenA - lenB; i++)
        {
            temp[i] = '0';
        }
        strcpy(temp + i, B);
        encrypt(A, temp, code);
    }
    else if (lenB > lenA)
    {
        for (i = 0; i < lenB - lenA; i++)
        {
            temp[i] = '0';
        }
        strcpy(temp + i, A);
        encrypt(temp, B, code);
    }
    else
    {
        encrypt(A, B, code);
    }

    printf("%s", code);

    return 0;
}
