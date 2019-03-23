#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

//ÅÐ¶Ï a ÊÇ·ñ¸²¸Ç b
bool isKey(int a, int b)
{
    while (a != 1)
    {
        if (a % 2 == 1) //ÆæÊý
        {
            a = (a * 3 + 1) / 2;
            if (a == b)
            {
                return true;
            }
        }
        else
        {
            a /= 2;
            if (a == b)
            {
                return true;
            }
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

        for (j = 0; j < buffer.size();) //ÅÐ¶Ïµ±Ç°¡°¹Ø¼ü¡±ÊÇ·ñ±»¸²¸Ç
        {
            if (isKey(buffer[j], temp))
            {
                break;
            }
            else if (isKey(temp, buffer[j]))
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
        for (int j = 0; j < buffer.size() - i - 1; j++)
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
        if (i != buffer.size() - 1)
        {
            printf("%d ", buffer[i]);
        }
        else
        {
            printf("%d", buffer[i]);
        }
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
