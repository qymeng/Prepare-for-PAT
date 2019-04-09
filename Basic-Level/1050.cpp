/* 1050 �������� */
//!!!��д�����ʱ��Ҫ����ͷ
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{
    return a >= b;
}

int main()
{
    int N, n, m, i, j, count;

    //1.����
    scanf("%d", &N);
    for (n = sqrt(N); n > 0; n--)
    {
        if (N % n == 0)
        {
            m = N / n;
            break;
        }
    }

    int *buffer = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", buffer + i);
    }
    sort(buffer, buffer + i, comp);

    //2.����
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    int raw = 0;
    int col = 0;
    for (i = 0, count = 0; count < N; i++)
    {
        j = i / 4;
        switch (i % 4)
        {
        case 0:
        {
            for (raw = j, col = j; col < n - j; col++)
            {
                matrix[raw][col] = buffer[count++];
            }
            break;
        }
        case 1:
        {
            for (raw++, col--; raw < m - j; raw++)
            {
                matrix[raw][col] = buffer[count++];
            }
            break;
        }
        case 2:
        {
            for (raw--, col--; col >= j; col--)
            {
                matrix[raw][col] = buffer[count++];
            }
        }
        case 3:
        {
            for (raw--, col++; raw > j; raw--)
            {
                matrix[raw][col] = buffer[count++];
            }
        }
        }
    }

    //3.��ӡ
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d%s", matrix[i][j], j == n - 1 ? "\n" : " ");
        }
    }

    //4.�ͷ�
    free(buffer);
    for (i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
