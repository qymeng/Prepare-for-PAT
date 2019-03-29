/* 1029 旧键盘 */
//!!!设置两个游标对字符串进行遍历
#include <stdio.h>

#define MAX_N 256 //ASCII符号数量
#define SIZE 81

int main()
{
    char text[SIZE] = "";
    char input[SIZE] = "";
    bool flag[MAX_N] = {0};
    int i, j;

    //1.输入
    scanf("%s%s", text, input);

    //2.查找错键并输出
    for (i = 0, j = 0; text[i] != '\0';)
    {
        char ch1 = text[i];
        char ch2 = input[j];

        if (ch1 != ch2) //必是错键
        {
            if (flag[ch1] == false) //这个错键是第一次发现
            {
                if (ch1 >= 'a' && ch1 <= 'z') //小写字母
                {
                    printf("%c", ch1 - 32);
                    flag[ch1] = true;
                    flag[ch1 - 32] = true;
                }
                else if (ch1 >= 'A' && ch1 <= 'Z') //大写字母
                {
                    printf("%c", ch1);
                    flag[ch1] = true;
                    flag[ch1 + 32] = true;
                }
                else //其他情况
                {
                    printf("%c", ch1);
                    flag[ch1] = true;
                }
            }

            i++; //只有text游标后移
        }
        else
        {
            i++;
            j++;
        }
    }

    return 0;
}
