/* 1029 �ɼ��� */
//!!!���������α���ַ������б���
#include <stdio.h>

#define MAX_N 256 //ASCII��������
#define SIZE 81

int main()
{
    char text[SIZE] = "";
    char input[SIZE] = "";
    bool flag[MAX_N] = {0};
    int i, j;

    //1.����
    scanf("%s%s", text, input);

    //2.���Ҵ�������
    for (i = 0, j = 0; text[i] != '\0';)
    {
        char ch1 = text[i];
        char ch2 = input[j];

        if (ch1 != ch2) //���Ǵ��
        {
            if (flag[ch1] == false) //�������ǵ�һ�η���
            {
                if (ch1 >= 'a' && ch1 <= 'z') //Сд��ĸ
                {
                    printf("%c", ch1 - 32);
                    flag[ch1] = true;
                    flag[ch1 - 32] = true;
                }
                else if (ch1 >= 'A' && ch1 <= 'Z') //��д��ĸ
                {
                    printf("%c", ch1);
                    flag[ch1] = true;
                    flag[ch1 + 32] = true;
                }
                else //�������
                {
                    printf("%c", ch1);
                    flag[ch1] = true;
                }
            }

            i++; //ֻ��text�α����
        }
        else
        {
            i++;
            j++;
        }
    }

    return 0;
}
