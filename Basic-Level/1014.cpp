/* 1014 ����Ħ˹��Լ�� */
/*
(1)������ڼ�����ĸ��Χ��A~G
(2)��ͬ��ָ�����ַ�����ͬλ�õ��ַ���ͬ
(3)����Сʱ������ĸӦ���ڡ����ڡ�֮��
(4)ʹ��STL���
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    const char *day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    const string hour = "0123456789ABCDEFGHIJKLMN";
    vector<string> buffer;
    string temp;

    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        buffer.push_back(temp);
    }

    int len = buffer[0].size();
    len = len < buffer[1].size() ? len : buffer[1].size();
    bool flag = false;

    for (int i = 0; i < len; i++)
    {
        char ch1 = buffer[0][i];
        char ch2 = buffer[1][i];
        if (!flag && ch1 >= 'A' && ch1 <= 'G')
        {
            if (ch1 == ch2)
            {
                printf("%s ", day[ch1 - 'A']);
                flag = true;
            }
        }
        else if (flag && hour.find(ch1) != temp.npos)
        {
            if (ch1 == ch2)
            {
                printf("%02d:", hour.find(ch1));
                break;
            }
        }
    }

    len = buffer[2].size();
    len = len < buffer[3].size() ? len : buffer[3].size();

    for (int i = 0; i < len; i++)
    {
        char ch1 = buffer[2][i];
        char ch2 = buffer[3][i];
        if (ch1 >= 'a' && ch1 <= 'z' || ch1 >= 'A' && ch1 <= 'Z')
        {
            if (ch1 == ch2)
            {
                printf("%02d", i);
                break;
            }
        }
    }

    return 0;
}
