/* 1071 С������ */
#include <stdio.h>

int main()
{

    //1.����
    int T, K;
    scanf("%d %d", &T, &K);

    int n1, b, t, n2;
    int i;
    bool flag = false;
    for (i = 0; i < K; i++)
    {
        scanf("%d %d %d %d", &n1, &b, &t, &n2);
        //����
        if (flag)
        {
            continue;
        }
        //�жϽ��
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
        //�ж����û
        if (T == 0)
        {
            flag = true;
            printf("Game Over.\n");
        }
    }

    return 0;
}
