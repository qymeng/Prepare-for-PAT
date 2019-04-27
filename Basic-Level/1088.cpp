/* 1088 三人行 */
//!!!丙可能是非整数
#include <stdio.h>
#include <math.h>

#define RADIX 10

int main()
{
    //1.输入
    int M, X, Y;
    scanf("%d %d %d", &M, &X, &Y);

    int a, b;
    double c;
    bool flag = false;
    for (a = 99; a >= RADIX; a--)
    {
        int temp = a % RADIX;
        b = temp * RADIX + a / RADIX;
        int difference = abs(a - b);
        if ((double)difference / (double)X == (double)b / (double)Y)
        {
            c = (double)difference / (double)X;
            flag = true;
            break;
        }
    }

    if (flag)
    {
        printf("%d %s %s %s",
               a,
               a > M ? "Cong" : a == M ? "Ping" : "Gai",
               b > M ? "Cong" : b == M ? "Ping" : "Gai",
               c > M ? "Cong" : c == M ? "Ping" : "Gai");
    }
    else
    {
        printf("No Solution");
    }

    return 0;
}
