/* 1050 螺旋矩阵 */
//!!!填写矩阵的时候，要顶到头
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

    //1.输入
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

    //2.填入
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

    //3.打印
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d%s", matrix[i][j], j == n - 1 ? "\n" : " ");
        }
    }

    //4.释放
    free(buffer);
    for (i = 0; i < m; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
