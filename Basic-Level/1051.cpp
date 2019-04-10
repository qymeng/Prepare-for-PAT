/* 1051 �����˷� */
//!!!�����Ǻ�������ת��
//A = A1 * A2 - B1 * B2;
//= (R1 * R2)cos(P1 + P2);
//B = A1 * B2 + A2 * B1;
//= (R1 * R2)sin(P1 + P2)

#include <stdio.h>
#include <math.h>

int main()
{
    double R1, P1, R2, P2;
    double A, B;

    //1.����
    scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
    A = (R1 * R2) * cos(P1 + P2);
    B = (R1 * R2) * sin(P1 + P2);

    //2.��ӡ
    if (fabs(A) < 0.005) //������0
    {
        printf("0.00");
    }
    else
    {
        printf("%.02lf", A);
    }

    if (B >= 0)
    {
        printf("+%.02lfi", B);
    }
    else if (fabs(B) < 0.005)
    {
        printf("+0.00i");
    }
    else
    {
        printf("%.02lfi", B);
    }

    return 0;
}
