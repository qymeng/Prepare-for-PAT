/* 1017 A����B */
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

    //1.��������뱻����
    cin >> A >> B;

    //*2.�ӵ㣺���������ܻ���ǰ��0
    int len_a = A.length();
    for (j = 0; j < len_a; j++)
    {
        if (A[j] != '0')
        {
            i = j; //��ʱiָ�����λ
            break;
        }
    }

    //*3.���������С�ڳ�������A��ʾһλ��
    R = A[i++] - '0';
    if (R < B && i == len_a - 1)
    {
        printf("%d %d", 0, R);
        return 0;
    }

    //*4.��ʽ��һ��(Ŀ��ʹ����û��ǰ��0)
    for (; R < B && i < len_a; i++)
    {
        R = R * 10 + (A[i] - '0');
    }

    j = 0;
    Q[j++] = R / B;
    R %= B;

    //5.һ���������
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
