/* 1069 ΢��ת���齱 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    //1.�������
    int M, N, S;
    cin >> M >> N >> S;

    //2.���û�����н�
    if (M < S)
    {
        string useless;
        for (int i = 0; i < M; i++)
        {
            cin >> useless;
        }
        cout << "Keep going..." << endl;
        return 0;
    }

    //3.����ID
    int i, j;
    string temp;
    vector<string> luckyman;
    for (i = 1; i < S; i++)
    {
        cin >> temp;
    }

    int lucky = 0;
    for (i = 0; i + S <= M; i++)
    {
        cin >> temp;
        if (i % N == lucky)
        {
            int n = luckyman.size();
            bool flag = true;
            for (j = 0; j < n; j++)
            {
                if (temp == luckyman[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                luckyman.push_back(temp);
                cout << temp << endl;
            }
            else
            {
                lucky++;
                lucky %= N;
            }
        }
    }

    return 0;
}
