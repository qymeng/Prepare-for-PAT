/*
��Ŀ��
1002 A+B for Polynomials 
��ɣ�
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
This time, you are supposed to find A+B where A and B are two polynomials.
(A��B�Ƕ���ʽ)
���룺
2 1 2.4 0 3.2
2 2 1.5 1 0.5
�����
3 2 1.5 1 2.9 0 3.2
ע��㣺
(1)���ʱָ�����䣬ϵ����ӡ�
(2)�ϲ�����ʽϵ��Ϊ0������ȥ��
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    double coefficient;
    int index;
};

bool comp(struct Node a, struct Node b)
{
    return a.index > b.index;
}

int main()
{
    //1.�������
    vector<struct Node> a, b;
    for (int i = 0; i < 2; i++)
    {
        int K;
        scanf("%d", &K);

        struct Node temp;
        for (int j = 0; j < K; j++)
        {
            scanf("%d %lf", &temp.index, &temp.coefficient);
            if (i == 0)
            {
                a.push_back(temp);
            }
            else
            {
                b.push_back(temp);
            }
        }

        if (i == 0)
        {
            sort(a.begin(), a.begin() + K, comp);
        }
        else
        {
            sort(b.begin(), b.begin() + K, comp);
        }
    }

    //2.��ӡ
    vector<struct Node> result;
    int i = 0, j = 0;
    while (1)
    {
        if (i >= a.size())
        {
            while (j < b.size())
            {
                result.push_back(b[j++]);
            }
            break;
        }
        else if (j >= b.size())
        {
            while (i < a.size())
            {
                result.push_back(a[i++]);
            }
            break;
        }

        if (a[i].index > b[j].index)
        {
            result.push_back(a[i++]);
        }
        else if (a[i].index < b[j].index)
        {
            result.push_back(b[j++]);
        }
        else
        {
            struct Node temp;
            temp.index = a[i].index;
            temp.coefficient = a[i++].coefficient + b[j++].coefficient;
            if (fabs(temp.coefficient) > 0)
            {
                result.push_back(temp);
            }
        }
    }

    printf("%d", result.size());
    for (int i = 0; i < result.size(); i++)
    {
        printf(" %d %.01lf", result[i].index, result[i].coefficient);
    }

    return 0;
}
