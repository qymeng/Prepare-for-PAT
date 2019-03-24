/* 1007 素数对猜想 */
#include <stdio.h>
#include <math.h>

//判断一个数是否是素数
bool isPrime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    if (n == 2)
    {
        return true;
    }

    int temp = (int)sqrt((double)n);
    int i;

    for (i = 2; i <= temp; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int input;
    scanf("%d", &input);

    int i, count = 0;
    for (i = 3; i <= input - 2; i++)
    {
        if (isPrime(i) && isPrime(i + 2))
        {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}