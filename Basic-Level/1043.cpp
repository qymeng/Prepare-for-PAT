/* 1043 输出PATest */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 10001
#define LEN 6
#define SIZE 128

int main()
{
    char buffer[MAX_LEN] = "";
    const char *str = "PATest";
    int ascii[SIZE] = {0};
    int count[LEN] = {0};

    //1.输入
    scanf("%s", buffer);

    //2.统计
    int len = strlen(buffer);
    int i;
    for (i = 0; i < len; i++)
    {
        ascii[buffer[i]]++;
    }
    for (i = 0; i < LEN; i++)
    {
        count[i] = ascii[str[i]];
    }

    //3.打印输出
    bool flag = true;
    for (i = 0; i != 0 || flag; i++, i %= LEN)
    {
        if (i == 0)
        {
            flag = false;
        }
        char temp = str[i];
        if (count[i] > 0)
        {
            count[i]--;
            printf("%c", temp);
            flag = true;
        }
    }

    return 0;
}
