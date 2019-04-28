/* 1091 N-自守数 */
#include <stdio.h>
#include <vector>
using namespace std;
#define BUFFER_SIZE 10

int main()
{
    //1.输入测试数
    int M;
    scanf("%d", &M);

    //2.输入测试
    int i, j;
    int temp;
    int result;
    bool flag;

    for (i = 0; i < M; i++)
    {
        scanf("%d", &temp);

        flag = false;
        for (j = 1; j < 10; j++)
        {
            result = temp * temp * j;
            if (temp == 1000)
            {
                if (result % 10000 == temp)
                {
                    flag = true;
                    break;
                }
            }
            else if (temp >= 100)
            {
                if (result % 1000 == temp)
                {
                    flag = true;
                    break;
                }
            }
            else if (temp >= 10)
            {
                if (result % 100 == temp)
                {
                    flag = true;
                    break;
                }
            }
            else
            {
                if (result % 10 == temp)
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
        {
            printf("%d %d\n", j, result);
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}
