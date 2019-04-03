/* 1034 有理数的四则运算 */
#include <stdio.h>
#include <math.h>

#define MAX_LEN 20

/*有理数结构体*/
struct RationalNumber
{
    bool sign;         //正负
    long long integer; //整数部分
    long long p;       //分子
    long long q;       //分母
};

//返回两个正整数的最大数
long long gcd(long long a, long long b)
{
    long long r;
    if (a < b)
    {
        r = a;
        a = b;
        b = r;
    }

    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

//转换为结构体
void convert(struct RationalNumber &num, long long a, long long b)
{
    num.sign = a >= 0 ? true : false;
    a = num.sign ? a : -a;

    long long commonFactor = gcd(a, b);
    a /= commonFactor;
    b /= commonFactor;

    num.integer = a / b;
    num.p = a - num.integer * b;
    num.q = b;
}

void compute(struct RationalNumber &result, long long type, long long a1, long long b1, long long a2, long long b2)
{
    switch (type)
    {
    case 0:
    {
        a1 = a1 * b2 + a2 * b1;
        b1 = b1 * b2;
        break;
    }
    case 1:
    {
        a1 = a1 * b2 - a2 * b1;
        b1 = b1 * b2;
        break;
    }
    case 2:
    {
        a1 *= a2;
        b1 *= b2;
        break;
    }
    case 3:
    {
        if (a2 < 0)
        {
            a2 = -a2;
            b2 = -b2;
        }
        a1 *= b2;
        b1 *= a2;
        if (b1 == 0)
        {
            return;
        }
    }
    }
    convert(result, a1, b1);
}

//打印有理数结构体
void printNum(struct RationalNumber num)
{
    printf("%s", num.sign ? "" : "(-");
    if (num.integer == 0 && num.p == 0)
    {
        printf("0");
    }
    else if (num.integer == 0)
    {
        printf("%lld/%lld", num.p, num.q);
    }
    else if (num.p == 0)
    {
        printf("%lld", num.integer);
    }
    else
    {
        printf("%lld %lld/%lld", num.integer, num.p, num.q);
    }
    printf("%s", num.sign ? "" : ")");
}

int main()
{
    long long a1, b1, a2, b2;
    int i;
    char buffer1[MAX_LEN] = "";
    char buffer2[MAX_LEN] = "";
    struct RationalNumber num1, num2, result;

    //1.输入
    scanf("%s%s", buffer1, buffer2);
    sscanf(buffer1, "%lld/%lld", &a1, &b1);
    sscanf(buffer2, "%lld/%lld", &a2, &b2);

    convert(num1, a1, b1);
    convert(num2, a2, b2);

    //2.计算输出
    for (i = 0; i < 4; i++)
    {
        printNum(num1);
        switch (i)
        {
        case 0:
        {
            printf(" + ");
            break;
        }
        case 1:
        {
            printf(" - ");
            break;
        }
        case 2:
        {
            printf(" * ");
            break;
        }
        case 3:
        {
            printf(" / ");
            break;
        }
        }
        printNum(num2);
        printf(" = ");

        compute(result, i, a1, b1, a2, b2);

        if (i == 3 && a2 == 0)
        {
            printf("Inf");
        }
        else
        {
            printNum(result);
        }

        printf("\n");
    }

    return 0;
}
