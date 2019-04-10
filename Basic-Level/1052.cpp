/* 1052 卖个萌 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_N 10
#define N 5

int getSymbal(const string buffer, string symbal[MAX_N])
{
    int i, count = 0;
    bool flag = false;
    int len = buffer.length();
    for (i = 0; i < len; i++)
    {
        char temp = buffer[i];
        if (temp == '[')
        {
            flag = true;
            continue;
        }
        else if (temp == ']')
        {
            flag = false;
            count++;
            continue;
        }
        if (flag)
        {
            symbal[count] += buffer[i];
        }
    }
    return count;
}

int main()
{
    string hand[MAX_N];
    string eye[MAX_N];
    string mouth[MAX_N];
    string buffer;
    int i, j, K, num;
    int nHand, nEye, nMouth;
    bool flag;

    // 1.输入符号
    for (i = 0; i < 3; i++)
    {
        getline(cin, buffer);
        switch (i)
        {
        case 0:
        {
            nHand = getSymbal(buffer, hand);
            break;
        }
        case 1:
        {
            nEye = getSymbal(buffer, eye);
            break;
        }
        case 2:
        {
            nMouth = getSymbal(buffer, mouth);
            break;
        }
        }
    }

    // 2.输入表情
    scanf("%d", &K);
    for (i = 0; i < K; i++)
    {
        buffer = "";
        flag = true;
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &num);
            if (flag)
            {
                switch (j)
                {
                case 0:
                {
                    if (num > 0 && num <= nHand)
                    {
                        buffer += hand[num - 1];
                        buffer += '(';
                    }
                    else
                    {
                        flag = false;
                    }
                    break;
                }
                case 4:
                {
                    if (num > 0 && num <= nHand)
                    {
                        buffer += ')';
                        buffer += hand[num - 1];
                    }
                    else
                    {
                        flag = false;
                    }
                    break;
                }
                case 1:
                case 3:
                {
                    if (num > 0 && num <= nEye)
                    {
                        buffer += eye[num - 1];
                    }
                    else
                    {
                        flag = false;
                    }
                    break;
                }
                case 2:
                {
                    if (num > 0 && num <= nMouth)
                    {
                        buffer += mouth[num - 1];
                    }
                    else
                    {
                        flag = false;
                    }
                    break;
                }
                }
            }
        }

        if (flag)
        {
            cout << buffer << endl;
        }
        else
        {
            cout << "Are you kidding me? @\\/@" << endl;
        }
    }

    return 0;
}
