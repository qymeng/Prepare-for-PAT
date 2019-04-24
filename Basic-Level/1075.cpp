/* 1075 链表元素分类 */
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

#define BUFFER_SIZE 100001

struct Node
{
    int address;
    int data;
    int next;
};

int main()
{
    //1.输入
    int start, N, K;
    scanf("%d %d %d", &start, &N, &K);

    struct Node buffer[BUFFER_SIZE], temp;
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &temp.address, &temp.data, &temp.next);
        buffer[temp.address] = temp;
    }

    //2.重排
    vector<struct Node> type1, type2, type3;

    while (start != -1)
    {
        temp = buffer[start];
        if (temp.data < 0)
        {
            type1.push_back(temp);
        }
        else if (temp.data <= K)
        {
            type2.push_back(temp);
        }
        else
        {
            type3.push_back(temp);
        }
        start = temp.next;
    }

    int n1 = type1.size();
    int n2 = type2.size();
    int n3 = type3.size();
    vector<struct Node> result;
    for (i = 0; i < n1; i++)
    {
        result.push_back(type1[i]);
    }
    for (i = 0; i < n2; i++)
    {
        result.push_back(type2[i]);
    }
    for (i = 0; i < n3; i++)
    {
        result.push_back(type3[i]);
    }

    //3.打印
    int len = result.size();
    for (i = 0; i < len - 1; i++)
    {
        printf("%05d %d %05d\n", result[i].address, result[i].data, result[i + 1].address);
    }
    printf("%05d %d -1\n", result[i].address, result[i].data);

    return 0;
}
