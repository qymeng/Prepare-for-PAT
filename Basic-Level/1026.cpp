/* 1026 ��������ʱ�� */
#include <stdio.h>

#define CLK_TCK 100

int main()
{
    int C1, C2;

    //1.����
    scanf("%d%d", &C1, &C2);

    //2.�������
    int ticks, time, hour, minute, second;

    ticks = C2 - C1;
    time = ticks / CLK_TCK + (ticks % CLK_TCK >= CLK_TCK / 2 ? 1 : 0); //��������

    second = time % 60;
    time -= second;
    time /= 60;

    minute = time % 60;
    time -= minute;
    time /= 60;

    hour = time;

    printf("%02d:%02d:%02d", hour, minute, second);

    return 0;
}
