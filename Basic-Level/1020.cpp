/* 1020 月饼 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX_N 1000

struct Info
{
    double amount;
    double total;
    double price;
};

bool comp(struct Info a, struct Info b)
{
    return a.price > b.price;
}

int main()
{
    int N, D, i;
    struct Info buffer[MAX_N];
    double total = 0;

    //1.输入
    scanf("%d%d", &N, &D);

    //2.输入
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &(buffer + i)->amount);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &(buffer + i)->total);
        (buffer + i)->price = (buffer + i)->total / (buffer + i)->amount;
    }

    //3.排序
    sort(buffer, buffer + N, comp);

    //4.算总价
    for (i = 0; D > 0; i++)
    {
        if (D > buffer[i].amount)
        {
            D -= buffer[i].amount;
            total += buffer[i].total;
        }
        else
        {
            total += buffer[i].price * D;
            D = 0;
        }
    }

    printf("%.02lf", total);

    return 0;
}
