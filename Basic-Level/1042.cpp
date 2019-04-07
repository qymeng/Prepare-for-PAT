/* 1042 字符统计 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_LEN 1001
#define N 26

int main()
{
    char buffer[MAX_LEN] = "";
    int i, len, max, maxIndex;
    int count[N] = {0};
    char temp;

    //1.输入
    cin.getline(buffer, MAX_LEN);

    //2.统计
    len = strlen(buffer);
    for (i = 0; i < len; i++)
    {
        temp = buffer[i];
        if (temp >= 'A' && temp <= 'Z')
        {
            count[temp - 'A']++;
        }
        else if (temp >= 'a' && temp <= 'z')
        {
            count[temp - 'a']++;
        }
    }

    //3.比较输出
    for (maxIndex = 0, max = count[0], i = 1; i < N; i++)
    {
        if (count[i] > max)
        {
            maxIndex = i;
            max = count[i];
        }
    }

    printf("%c %d", 'a' + maxIndex, max);

    return 0;
}
