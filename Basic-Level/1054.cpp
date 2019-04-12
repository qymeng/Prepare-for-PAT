/* 1054 ��ƽ��ֵ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define SIZE 100

bool isLegal(const char *buffer)
{
    int len = strlen(buffer);
    int index = 0;

    //1.�Ƿ��Ǹ���
    if (buffer[index] == '-')
    {
        index++;
    }
    if (index == len)
    {
        return false;
    }
    //2.�жϵ�һ��С����֮ǰ��λ
    for (; index < len && buffer[index] != '.'; index++)
    {
        if (!isdigit(buffer[index]))
        {
            return false;
        }
    }
    //3.�ж�С��λ
    if (index < len && buffer[index] == '.')
    {
        for (int j = index + 1; j < len; j++)
        {
            if (!isdigit(buffer[j]) || (j - index) > 2)
            {
                return false;
            }
        }
    }
    //4.�Ƿ񳬳���Χ
    double temp = fabs(atof(buffer));
    if (temp > 1000.0)
    {
        return false;
    }
    //5.ȫ��ͨ��
    return true;
}

int main()
{
    int N, i, count = 0;
    char buffer[SIZE];
    double sum = 0;

    //1.����
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s", buffer);

        if (isLegal(buffer))
        {
            count++;
            sum += atof(buffer);
        }
        else
        {
            printf("ERROR: %s is not a legal number\n", buffer);
        }
    }
    //2.���
    if (count == 0)
    {
        printf("The average of 0 numbers is Undefined\n");
    }
    else if (count == 1)
    {
        printf("The average of 1 number is %.02lf\n", sum);
    }
    else
    {
        printf("The average of %d numbers is %.02lf\n", count, sum / (double)count);
    }

    return 0;
}
