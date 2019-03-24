/* 1002 写出这个数 */
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100 //n小于10的100次方，说明最多99位 
                    //求和之后不超过1000

//获取百位、十位、个位数字
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

    int i, sum = 0;
    int len = strlen(buffer);
    for (i = 0; i < len; i++)
    {
        sum += buffer[i] - '0';
    }

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