/* 1071 小赌怡情 */
#include <stdio.h>

int main()
{

    //1.输入
    int T, K;
    scanf("%d %d", &T, &K);

    int n1, b, t, n2;
    int i;
    bool flag = false;
    for (i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        //输光后
        if (flag)
        {
            continue;
        }
        //判断结果
        if (T < t)
        {
            printf("Not enough tokens.  Total = %d.\n", T);
        }
        else if (n2 < n1 && b == 0 || n2 > n1 && b == 1)
        {
            T += t;
            printf("Win %d!  Total = %d.\n", t, T);
        }
        else if (n2 < n1 && b == 1 || n2 > n1 && b == 0)
        {
            T -= t;
            printf("Lose %d.  Total = %d.\n", t, T);
        }
        //判断输光没
        if (T == 0)
        {
            flag = true;
            printf("Game Over.\n");
        }
    }

    return 0;
}
