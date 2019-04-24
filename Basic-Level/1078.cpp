/* 1078 ◊÷∑˚¥Æ—πÀı”ÎΩ‚—π */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define BUFFER_SIZE 1001

int main()
{
    //1. ‰»Î
    char option;
    scanf("%c", &option);
    getchar();

    char buffer[BUFFER_SIZE];
    //fgets(buffer, BUFFER_SIZE, stdin);
    cin.getline(buffer, BUFFER_SIZE);
    int len = strlen(buffer);

    if (option == 'C')
    {
        int i;
        char current, next;
        int count = 1;
        bool flag = false;

        for (i = 0; i < len - 1; i++)
        {
            current = buffer[i];
            next = buffer[i + 1];
            if (current == next)
            {
                flag = true;
                count++;
            }
            else
            {
                flag = false;
                if (count > 1)
                {
                    printf("%d%c", count, current);
                }
                else
                {
                    printf("%c", current);
                }
                count = 1;
            }
        }

        if (flag)
        {
            printf("%d%c", count, current);
        }
        else
        {
            printf("%c", buffer[len - 1]);
        }
    }
    else
    {
        int i, j;
        char temp;
        int count = 0;

        for (i = 0; i < len; i++)
        {
            temp = buffer[i];

            if (temp >= '0' && temp <= '9')
            {
                count *= 10;
                count += temp - '0';
            }
            else
            {
                if (count == 0)
                {
                    printf("%c", temp);
                }
                else
                {
                    for (j = 0; j < count; j++)
                    {
                        printf("%c", temp);
                    }
                    count = 0;
                }
            }
        }
    }

    return 0;
}
