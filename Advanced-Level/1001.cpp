/*
题目：
1001 A+B Format 
题干：
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
输入：
-1000000 9
输出：
-999,991
*/
#include <stdio.h>

int main()
{
    //1.输入计算
    int a, b;
    scanf("%d %d", &a, &b);
    int result = a + b;

    //2.打印
    if (result < 0)
    {
        printf("-");
        result = -result;
    }
    if (result >= 1000000)
    {
        int temp = result / 1000000;
        printf("%d,", temp);

        temp = result / 1000 % 1000;
        printf("%03d,", temp);

        temp = result % 1000;
        printf("%03d", temp);
    }
    else if (result >= 1000)
    {
        int temp = result / 1000;
        printf("%d,", temp);

        temp = result % 1000;
        printf("%03d", temp);
    }
    else
    {
        printf("%d", result);
    }

    return 0;
}
