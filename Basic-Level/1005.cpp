/* 1005 继续(3n+1)猜想 */
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

//判断 a 是否覆盖 b
bool cover(int a, int b)
{
    while (a != 1)
    {
        if (a % 2 == 1) //奇数
        {
            a = a * 3 + 1;
        }
        a >>= 1;

        if (a == b)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, i, j;
    scanf("%d", &n);

    vector<int> buffer;
    int count = 0;

    for (i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);

        for (j = 0; j < buffer.size();) //判断当前“关键”是否被覆盖
        {
            if (cover(buffer[j], temp))
            {
                break;
            }
            else if (cover(temp, buffer[j]))
            {
                buffer.erase(buffer.begin() + j);
            }
            else
            {
                j++;
            }
        }
        if (j == buffer.size())
        {
            buffer.push_back(temp);
        }
    }

    for (i = 0; i < buffer.size(); i++)
    {
        for (j = 0; j < buffer.size() - i - 1; j++)
        {
            if (buffer[j] < buffer[j + 1])
            {
                int temp = buffer[j];
                buffer[j] = buffer[j + 1];
                buffer[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < buffer.size(); i++)
    {
        printf("%d%s", buffer[i], i == buffer.size() - 1 ? "" : " ");
    }
    return 0;
}

/*
3:5 8 4 2 1 
5:8 4 2 1 
6:3 5 8 4 2 1 
7:11 17 26 13 20 10 5 8 4 2 1 
8:4 2 1 
11:17 26 13 20 10 5 8 4 2 1 
*/
