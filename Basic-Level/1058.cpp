/* 1058 ѡ���� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Question
{
    int mark;       //��Ŀ����
    int useless;    //ѡ����������ã�
    int num;        //��ȷ��ѡ�����
    int count;      //���˵�ѧ����
    int no;         //���
    bool answer[5]; //����Ϣ
};

bool comp(struct Question q1, struct Question q2)
{
    return q1.count > q2.count;
}

int main()
{
    //1.������Ŀ����ѧ����
    int N, M;
    scanf("%d%d", &N, &M);

    //2.�������
    struct Question *buffer = (struct Question *)malloc(M * sizeof(struct Question));
    memset(buffer, 0, M * sizeof(struct Question));
    int i, j, n;
    char temp[2];
    for (i = 0; i < M; i++)
    {
        scanf("%d%d%d", &buffer[i].mark, &buffer[i].useless, &n);
        buffer[i].num = n;
        buffer[i].no = i + 1;
        for (j = 0; j < n; j++)
        {
            scanf("%s", temp);
            buffer[i].answer[temp[0] - 'a'] = true;
        }
    }

    //3.����ѧ����
    getchar();

    string answer;
    int grade, len, no, k;
    char ch;
    bool flag;
    for (i = 0; i < N; i++)
    {
        grade = 0;
        getline(cin, answer);
        len = answer.length();

        no = -1; //���
        for (j = 0; j < len; j++)
        {
            ch = answer[j];
            if (ch >= '0' && ch <= '9')
            {
                no++;
                n = ch - '0';
                flag = true;
                k = 0;
                continue;
            }
            if (ch >= 'a' && ch <= 'e')
            {
                k++;

                if (!buffer[no].answer[ch - 'a'])
                {
                    flag = false;
                }

                if (k == n)
                {
                    if (flag && n == buffer[no].num)
                    {
                        grade += buffer[no].mark;
                    }
                    else
                    {
                        buffer[no].count++;
                    }
                }
            }
        }

        printf("%d\n", grade);
    }

    //4.�Ҵ���
    // for (i = 0; i < M; i++)
    // {
    //     printf("%d ", buffer[i].count);
    // }
    // printf("\n");

    sort(buffer, buffer + M, comp);
    int max = buffer[0].count;
    if (max == 0)
    {
        printf("Too simple");
    }
    else
    {
        printf("%d", max);
        for (i = 0; buffer[i].count == max; i++)
        {
            printf(" %d", buffer[i].no);
        }
    }

    free(buffer);
    return 0;
}
