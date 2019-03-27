/* 1017 A除以B */
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#define MAX_LEN 1000

int main()
{
    string A;
    int B;
    int i, j;
    int Q[MAX_LEN] = {0}, R;

    //1.输入除数与被除数
    cin >> A >> B;

    //*2.坑点：被除数可能会有前导0
    int len_a = A.length();
    for (j = 0; j < len_a; j++)
    {
        if (A[j] != '0')
        {
            i = j; //此时i指向最高位
            break;
        }
    }

    //*3.如果该数字小于除数并且A表示一位数
    R = A[i++] - '0';
    if (R < B && i == len_a - 1)
    {
        printf("%d %d", 0, R);
        return 0;
    }

    //*4.竖式第一项(目的使余数没有前导0)
    for (; R < B && i < len_a; i++)
    {
        R = R * 10 + (A[i] - '0');
    }

    j = 0;
    Q[j++] = R / B;
    R %= B;

    //5.一般项的求余
    for (; i < len_a; i++)
    {
        R = R * 10 + (A[i] - '0');
        Q[j++] = R / B;
        R %= B;
    }

    for (i = 0; i < j; i++)
    {
        printf("%d", Q[i]);
    }
    printf(" %d", R);

    return 0;
}
