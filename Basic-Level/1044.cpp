/* 1044 火星数字 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_N 100
#define MAX_LEN 20
#define RADIX 13

int getIndex(const char *str, const char **buffer)
{
    int i;
    for (i = 1; i < RADIX; i++)
    {
        if (strcmp(str, buffer[i]) == 0)
        {
            return i;
        }
    }
    return 0;
}

int getIndex(const char *str, const char **buffer, int n)
{
    int i;
    for (i = 1; i < RADIX; i++)
    {
        if (strncmp(str, buffer[i], n) == 0)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    const char *ones[] = {"tret", "jan", "feb",
                          "mar", "apr", "may", "jun", "jly",
                          "aug", "sep", "oct", "nov", "dec"};
    const char *tens[] = {"", "tam", "hel",
                          "maa", "huh", "tou", "kes", "hei",
                          "elo", "syy", "lok", "mer", "jou"};
    int N, i, num, len;
    char buffer[MAX_LEN], assist[MAX_LEN];

    //1.输入
    scanf("%d", &N);
    getchar();

    for (i = 0; i < N; i++)
    {
        cin.getline(buffer, MAX_LEN);

        num = atoi(buffer);
        len = strlen(buffer);

        char temp = buffer[0];
        if (temp >= '0' && temp <= '9') //地球文转火星文
        {
            if (num == 0) //0
            {
                printf("%s%s", ones[0], i == N - 1 ? "" : "\n");
            }
            else if (num < RADIX) //1位火星文
            {
                printf("%s%s", ones[num], i == N - 1 ? "" : "\n");
            }
            else if (num % RADIX == 0) //2位火星文
            {
                printf("%s%s", tens[num / RADIX], i == N - 1 ? "" : "\n");
            }
            else
            {
                printf("%s ", tens[num / RADIX]);
                printf("%s%s", ones[num % RADIX], i == N - 1 ? "" : "\n");
            }
        }
        else //火星文转地球文
        {
            if (len == 4)
            {
                printf("%d%s", 0, i == N - 1 ? "" : "\n");
            }
            else if (len < 4)
            {
                num = getIndex(buffer, ones);
                if (num)
                {
                    printf("%d%s", num, i == N - 1 ? "" : "\n");
                    continue;
                }
                num = getIndex(buffer, tens);
                printf("%d%s", num * RADIX, i == N - 1 ? "" : "\n");
            }
            else
            {
                num = getIndex(buffer, tens, 3) * RADIX;
                num += getIndex(buffer + 4, ones);
                printf("%d%s", num, i == N - 1 ? "" : "\n");
            }
        }
    }

    return 0;
}
