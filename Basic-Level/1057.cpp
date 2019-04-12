/* 1057 数零壹 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_LEN 100001

int main()
{
    //1.输入
    char buffer[MAX_LEN];
    cin.getline(buffer, MAX_LEN, '\n');

    //2.计数
    int len = strlen(buffer);
    int i, sum = 0;
    char temp;
    for (i = 0; i < len; i++)
    {
        temp = buffer[i];
        if (temp >= 'a' && temp <= 'z')
        {
            sum += temp - 'a' + 1;
        }
        else if (temp >= 'A' && temp <= 'Z')
        {
            sum += temp - 'A' + 1;
        }
    }

    int zero = 0, one = 0;
    while (sum != 0)
    {
        if (sum % 2 == 0)
        {
            zero++;
        }
        else
        {
            one++;
        }
        sum /= 2;
    }

    printf("%d %d", zero, one);

    return 0;
}
