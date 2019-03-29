/* 1031 查验身份证 */
#include <stdio.h>

#define SIZE 19
#define WEIGHT_SIZE 17
#define CODE_SIZE 11

int main()
{
    const int weight[WEIGHT_SIZE] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    const char code[CODE_SIZE + 1] = "10X98765432";

    int N, i, j, sum;
    bool flag, all = true;
    char buffer[SIZE];

    //1.输入
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%s", buffer);

        for (j = 0, sum = 0, flag = true; j < WEIGHT_SIZE; j++)
        {
            char ch = buffer[j];
            if (ch >= '0' && ch <= '9')
            {
                sum += (buffer[j] - '0') * weight[j]; //加权求和
            }
            else
            {
                flag = false;
                break;
            }
        }
        sum %= CODE_SIZE;

        if (!flag || buffer[SIZE - 2] != code[sum])
        {
            printf("%s\n", buffer);
            all = false;
        }
    }

    if (all == true)
    {
        printf("%s", "All passed");
    }

    return 0;
}
