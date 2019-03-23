#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int getNum(int sum, int n)
{
    switch (n)
    {
    case 2:
    {
        return sum / 100;
    }
    case 1:
    {
        return sum % 100 / 10;
    }
    case 0:
    {
        return sum % 10;
    }
    }
}

int main()
{
    const char *num[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char buffer[MAX_LEN] = "";

    scanf("%s", buffer);

    int i = 0;
    int len = strlen(buffer);
    int sum = 0;

    for (; i < len; i++)
    {
        sum += buffer[i] - '0';
    }

    int flag = 0;

    int hundred = getNum(sum, 2);
    if (hundred != 0)
    {
        printf("%s ", num[hundred]);
    }

    int ten = getNum(sum, 1);
    if (hundred || ten != 0)
    {
        printf("%s ", num[ten]);
    }

    int one = getNum(sum, 0);
    printf("%s", num[one]);

    return 0;
}