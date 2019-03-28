/* 1025 ��ת���� */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 100000

struct Node
{
    int address;
    int data;
    int next;
};

int main()
{
    int start, N, K;
    int i;
    struct Node buffer[MAX_N], temp;
    vector<struct Node> list;

    //1.����
    scanf("%d%d%d", &start, &N, &K);

    for (i = 0; i < N; i++)
    {
        scanf("%d%d%d", &temp.address, &temp.data, &temp.next);
        buffer[temp.address] = temp; //����bufferģ��ʵ���ڴ�
    }

    //2.ȡ������
    while (start != -1)
    {
        list.push_back(buffer[start]);
        start = buffer[start].next;
    }
    N = list.size(); //ʵ���в��������е�Ԫ��

    //3.���з�ת
    for (i = 0; i + K <= N; i += K)
    {
        reverse(list.begin() + i, list.begin() + i + K);
    }

    //4.�޸�Ԫ��
    for (i = 0; i < N - 1; i++)
    {
        list[i].next = list[i + 1].address;
    }
    list[i].next = -1;

    //5.��ӡ
    for (i = 0; i < N - 1; i++)
    {
        printf("%05d %d %05d\n", list[i].address, list[i].data, list[i].next);
    }
    printf("%05d %d -1", list[i].address, list[i].data);

    return 0;
}
