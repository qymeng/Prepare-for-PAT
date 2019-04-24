/* 1079 延迟的回文数 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_ITERATIONS 10
#define RADIX 10

bool isPalindromic(vector<int> &buffer)
{
    int len = buffer.size();
    int i;
    for (i = 0; i < len; i++)
    {
        if (buffer[i] != buffer[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //1.输入原始数字
    string input;
    cin >> input;

    //2.转移到容器中去
    vector<int> buffer[2];
    int len = input.length();
    int i, j;
    for (i = 0; i < len; i++)
    {
        buffer[0].push_back(input[i] - '0');
    }

    //3.判断初始
    if (isPalindromic(buffer[0]))
    {
        cout << input << " is a palindromic number.";
        return 0;
    }

    //4.迭代
    int initial, assist;
    int carry;
    int temp;
    for (i = 0; i < MAX_ITERATIONS; i++)
    {
        initial = i % 2;
        assist = 1 - initial;

        len = buffer[initial].size();
        for (j = 0; j < len; j++)
        {
            printf("%d", buffer[initial][j]);
        }
        printf(" + ");
        for (j = len - 1; j >= 0; j--)
        {
            printf("%d", buffer[initial][j]);
        }
        printf(" = ");

        buffer[assist].clear();
        carry = 0;
        for (j = 0; j < len; j++)
        {
            temp = buffer[initial][j] + buffer[initial][len - 1 - j] + carry;
            carry = temp / RADIX;
            temp %= RADIX;
            buffer[assist].push_back(temp);
        }
        if (carry > 0)
        {
            buffer[assist].push_back(carry);
        }
        len = buffer[assist].size();
        reverse(buffer[assist].begin(), buffer[assist].begin() + len);

        for (j = 0; j < len; j++)
        {
            printf("%d", buffer[assist][j]);
        }
        printf("\n");

        if (isPalindromic(buffer[assist]))
        {
            for (j = 0; j < len; j++)
            {
                printf("%d", buffer[assist][j]);
            }
            printf(" is a palindromic number.");
            return 0;
        }
    }

    printf("Not found in %d iterations.", MAX_ITERATIONS);

    return 0;
}
