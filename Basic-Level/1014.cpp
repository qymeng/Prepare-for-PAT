/* 1014 福尔摩斯的约会 */
/*
(1)输出星期几的字母范围是A~G
(2)相同是指两个字符串相同位置的字符相同
(3)代表“小时”的字母应该在“星期”之后
(4)使用STL完成
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
