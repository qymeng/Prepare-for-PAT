/* 1081 检查密码 */
//!!!一次读取一行
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define BUFFER_SIZE 81

int main()
{
    //1.输入
    int N;
    scanf("%d", &N);
    getchar();

    //2.检查
    char buffer[BUFFER_SIZE];
    int i, j, len;
    char ch;
    int countDigit, countAlphabet;
    bool flag;
    for (i = 0; i < N; i++)
    {
        cin.getline(buffer, BUFFER_SIZE);

        len = strlen(buffer);
        //1.是否太短
        if (len < 6)
        {
            printf("Your password is tai duan le.\n");
            continue;
        }
        //2.判断字符
        countDigit = 0;
        countAlphabet = 0;
        flag = false;
        for (j = 0; j < len; j++)
        {
            ch = buffer[j];
            if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            {
                countAlphabet++;
            }
            else if (ch >= '0' && ch <= '9')
            {
                countDigit++;
            }
            else if (ch != '.')
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            printf("Your password is tai luan le.\n");
            continue;
        }
        if (countDigit == 0)
        {
            printf("Your password needs shu zi.\n");
            continue;
        }
        if (countAlphabet == 0)
        {
            printf("Your password needs zi mu.\n");
            continue;
        }
        //3.没有问题
        printf("Your password is wan mei.\n");
    }

    return 0;
}
