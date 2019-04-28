/* 1093 ×Ö·û´®A+B */
#include <iostream>
#include <string.h>
using namespace std;

#define BUFFER_SIZE 128
#define MAX_LEN 1000001

int main()
{
    bool flag[BUFFER_SIZE] = {0};

    char buffer[MAX_LEN];
    int i, j;
    int len;
    char temp;
    for (i = 0; i < 2; i++)
    {
        cin.getline(buffer, MAX_LEN);

        len = strlen(buffer);
        for (j = 0; j < len; j++)
        {
            temp = buffer[j];
            if (!flag[temp])
            {
                flag[temp] = true;
                printf("%c", temp);
            }
        }
    }

    return 0;
}
