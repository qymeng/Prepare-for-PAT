/* 1074 宇宙无敌加法器 */
#include <stdio.h>
#include <string.h>

#define MAX_N 21

int main()
{

    //1.输入
    char bufferRadix[MAX_N];
    char bufferA[MAX_N];
    char bufferB[MAX_N];
    scanf("%s %s %s", bufferRadix, bufferA, bufferB);

    int bitsOfRadix = strlen(bufferRadix);
    int bitsOfA = strlen(bufferA);
    int bitsOfB = strlen(bufferB);

    int radix[MAX_N] = {0};
    int a[MAX_N] = {0};
    int b[MAX_N] = {0};

    int i;
    for (i = 0; i < bitsOfRadix; i++)
    {
        radix[i] = bufferRadix[i] - '0';
    }
    for (i = 0; i < bitsOfA; i++)
    {
        a[i] = bufferA[i] - '0';
    }
    for (i = 0; i < bitsOfB; i++)
    {
        b[i] = bufferB[i] - '0';
    }

    //2.对齐
    int bits = bitsOfA;
    if (bitsOfA > bitsOfB) //A位数多
    {
        int difference = bitsOfA - bitsOfB;
        bits = bitsOfA;
        for (i = bitsOfB - 1; i >= 0; i--)
        {
            b[i + difference] = b[i];
        }
        for (i = 0; i < difference; i++)
        {
            b[i] = 0;
        }
    }
    else if (bitsOfA < bitsOfB)
    {
        int difference = bitsOfB - bitsOfA;
        bits = bitsOfB;
        for (i = bitsOfA - 1; i >= 0; i--)
        {
            a[i + difference] = a[i];
        }
        for (i = 0; i < difference; i++)
        {
            a[i] = 0;
        }
    }

    //3.计算
    int result[MAX_N];
    int carry = 0;
    int temp;
    int tempRadix;

    for (i = 0; i < bits; i++)
    {
        temp = a[bits - 1 - i] + b[bits - 1 - i] + carry;
        if (radix[bitsOfRadix - 1 - i] == 0)
        {
            tempRadix = 10;
        }
        else
        {
            tempRadix = radix[bitsOfRadix - 1 - i];
        }
        result[bits - 1 - i] = temp % tempRadix;
        carry = temp / tempRadix;
    }

    //4.打印
    bool flag = false;
    if (carry > 0)
    {
        printf("%d", carry);
        flag = true;
    }
    for (i = 0; i < bits; i++)
    {
        temp = result[i];
        if (!flag)
        {
            if (temp != 0)
            {
                flag = true;
            }
        }
        if (flag)
        {
            printf("%d", temp);
        }
    }

    if (!flag)
    {
        printf("0");
    }

    return 0;
}
