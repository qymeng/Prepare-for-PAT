/* 1090 危险品装箱 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define BUFFER_SIZE 10000

int main()
{
    //1.输入参数
    int N, M;
    scanf("%d %d", &N, &M);

    //2.输入不相容
    map<int, vector<int>> incompatible;
    int i, j, k;
    int a, b;
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        incompatible[a].push_back(b);
        incompatible[b].push_back(a);
    }

    //3.输入箱中货物信息
    int K;
    int temp;
    int len;
    for (i = 0; i < M; i++)
    {
        scanf("%d", &K);
        printf("i = %d K = %d\n", i, K);

        bool flag[BUFFER_SIZE] = {0};
        buffer.clear();
        for (j = 0; j < K; j++)
        {
            scanf("%d", &temp);
            buffer.push_back(temp);
            flag[temp] = true;
        }

        for (j = 0; j < K; j++)
        {
            temp = buffer[j];
            len = incompatible[temp].size();
            for (k = 0; k < len; k++)
            {
                if (flag[incompatible[temp][k]])
                {
                    printf("No\n");
                }
            }
        }

        printf("Yes\n");
    }

    return 0;
}
