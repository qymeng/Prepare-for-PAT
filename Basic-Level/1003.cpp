/* 1003 我要通过！ */
//主要是寻找规律，
//以P和T为分界线，A的数量，left*mid=right
#include <stdio.h>
#include <string.h>

#define MAX_N 10
#define MAX_LEN 100

int check(const char *str)
{
    int i, len = strlen(str);
    char ch;
    int flag = 0;
    int left = 0;
    int mid = 0;
    int right = 0;

    for (i = 0; i < len; i++)
    {
        ch = str[i];
        if (ch != 'P' && ch != 'A' && ch != 'T')
        {
            return 0;
        }

        if (flag == 0)
        {
            if (ch == 'P')
            {
                flag++;
            }
            else if (ch == 'A')
            {
                left++;
            }
            else
            {
                return 0;
            }
        }
        else if (flag == 1)
        {
            if (ch == 'A')
            {
                flag++;
                mid++;
            }
            else
            {
                return 0;
            }
        }
        else if (flag == 2)
        {
            if (ch == 'P')
            {
                return 0;
            }
            else if (ch == 'A')
            {
                mid++;
            }
            else
            {
                flag++;
            }
        }
        else
        {
            if (ch == 'A')
            {
                right++;
            }
            else
            {
                return 0;
            }
        }
    }

    if (flag == 3 && left * mid == right)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    const char *result[] = {"NO", "YES"};
    char buffer[MAX_N][MAX_LEN] = {0};

    int i, n = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", buffer + i);
        printf("%s%s", result[check(buffer[i])], (i == n - 1 ? "" : "\n"));
    }

    return 0;
}
