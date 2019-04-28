/* 1090 Σ��Ʒװ�� */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

#define BUFFER_SIZE 100000

int main()
{
    //1.�������
    int N, M;
    scanf("%d %d", &N, &M);

    //2.���벻����
    map<int, vector<int>> incompatible;
    int i, j, k;
    int a, b;
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        incompatible[a].push_back(b);
        incompatible[b].push_back(a);
    }

    //3.�������л�����Ϣ
    int K;
    int temp;
    int len;
    bool assist[BUFFER_SIZE];
    for (i = 0; i < M; i++)
    {
        scanf("%d", &K);

        vector<int> buffer;
        memset(assist, 0, BUFFER_SIZE);
        for (j = 0; j < K; j++)
        {
            scanf("%d", &temp);
            buffer.push_back(temp);
            assist[temp] = true;
        }

        bool flag = true;
        for (j = 0; j < K && flag; j++)
        {
            temp = buffer[j];
            len = incompatible[temp].size();
            for (k = 0; k < len; k++)
            {
                if (assist[incompatible[temp][k]])
                {
                    printf("No\n");
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
        {
            printf("Yes\n");
        }
    }

    return 0;
}
