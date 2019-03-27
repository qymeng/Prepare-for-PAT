/* 1003 ÊıËØÊı */
//*****************************************8
#include <stdio.h>
#include <math.h>

#define MAX_N 105000

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
    int M, N, i, count;
    int buffer[MAX_N] = {0};

    scanf("%d%d", &M, &N);
    for (i = 2, count = 1; i < MAX_N; i++)
    {
        if (isPrime(i))
        {
            buffer[count++] = i;
        }
    }

    for (count = 0, i = M; i <= N; i++)
    {
        if (count % 10)
        {
            printf(" ");
        }
        printf("%d", buffer[i]);
        count++;
        if (count % 10 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}
