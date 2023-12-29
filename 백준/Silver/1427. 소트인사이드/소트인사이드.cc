#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int a = 0;
    cin >> a;

    string k = to_string(a);

    for (int i = 0; i < k.length(); i++)
    {
        for (int j = i; j < k.length(); j++)
        {
            if (k[i] < k[j])
            {
                int temp = k[j];
                k[j] = k[i];
                k[i] = temp;
            }
        }
        cout << k[i];
    }

    return 0;
}