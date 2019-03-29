/* 1033 坏键盘打字 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_N 256
#define MAX_LEN 100000

int main()
{
    char broken[MAX_LEN + 1] = "";
    char input[MAX_LEN + 1] = "";
    bool flag[MAX_N] = {0};

    //1.输入
    cin.getline(broken, MAX_LEN);
    cin.getline(input, MAX_LEN);

    //2.解析
    int len = strlen(broken);
    int i;
    for (i = 0; i < len; i++)
    {
        char temp = broken[i];
        flag[temp] = true;
        if (temp >= 'A' && temp <= 'Z')
        {
            flag[temp + 32] = true;
        }
    }
    if (flag['+'])
    {
        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            flag[ch] = true;
        }
    }

    //3.打印
    len = strlen(input);
    for (i = 0; i < len; i++)
    {
        char temp = input[i];
        if (flag[temp])
        {
            continue;
        }
        else
        {
            printf("%c", temp);
        }
    }
    printf("\n");

    return 0;
}
