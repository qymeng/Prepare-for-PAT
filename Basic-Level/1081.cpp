/* 1081 ������� */
//!!!һ�ζ�ȡһ��
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define BUFFER_SIZE 81

int main()
{
    //1.����
    int N;
    scanf("%d", &N);
    getchar();

    //2.���
    char buffer[BUFFER_SIZE];
    int i, j, len;
    char ch;
    int countDigit, countAlphabet;
    bool flag;
    for (i = 0; i < N; i++)
    {
        cin.getline(buffer, BUFFER_SIZE);

        len = strlen(buffer);
        //1.�Ƿ�̫��
        if (len < 6)
        {
            printf("Your password is tai duan le.\n");
            continue;
        }
        //2.�ж��ַ�
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
        //3.û������
        printf("Your password is wan mei.\n");
    }

    return 0;
}
