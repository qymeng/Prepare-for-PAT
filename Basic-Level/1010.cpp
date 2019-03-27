/* 1010 一元多项式求导 */
#include <stdio.h>

int main()
{
    int coef, index, count = 0;

    while (scanf("%d %d", &coef, &index) != EOF)
    {
        if (index)
        {
            if (count++)
            {
                putchar(' ');
            }
            printf("%d %d", coef * index, index - 1);
        }
    }

    if (count == 0)
    {
        printf("0 0");
    }

    return 0;
}