/* 1067 ������ */
//!!!������ȷ�����ʱ���޿ո񣬿�����cin��֮���������ʱ���Ƕ�һ��
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string password;
    int N;
    cin >> password >> N;
    getchar();

    vector<string> input;
    string temp;
    while (1)
    {
        getline(cin, temp);
        if (temp == "#")
        {
            break;
        }
        input.push_back(temp);
    }

    int i, n = input.size();
    for (i = 0; i < n; i++)
    {
        if (i < N)
        {
            if (input[i] == password)
            {
                cout << "Welcome in" << endl;
                return 0;
            }
            else
            {
                cout << "Wrong password: " << input[i] << endl;
                if (i == N - 1)
                {
                    cout << "Account locked" << endl;
                }
            }
        }
    }

    return 0;
}
