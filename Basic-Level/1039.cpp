/* 1039 µ½µ×Âò²»Âò */
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001
#define SIZE 128

int main()
{
    int count[SIZE] = {0};
    char buffer[MAX_LEN] = "";

    int i, len;
    int yes = 0, no = 0;
    bool flag = true;

    scanf("%s", buffer);
    len = strlen(buffer);
    for (i = 0; i < len; i++)
    {
        count[buffer[i]]++;
    }

    scanf("%s", buffer);
    len = strlen(buffer);
    for (i = 0; i < len; i++)
    {
        char ch = buffer[i];
        count[ch]--;
        if (count[ch] < 0)
        {
            flag = false;
            no++;
        }
    }

    if (!flag)
    {
        printf("No %d", no);
        return 0;
    }

    for (i = 0; i < SIZE; i++)
    {
        if (count[i] > 0)
        {
            yes += count[i];
        }
    }

    printf("Yes %d", yes);

    return 0;
}
