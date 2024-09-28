#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> hashSet;
    string N = "";
    cin >> N;

    int count = 0;
    for (int i = 0; i < N.length(); i++)
    {
        for (int j = 0; j+i < N.length(); j++)
        {
            string temp = "";
            temp= N.substr(j, i+1);
            if (hashSet.find(temp) == hashSet.end())
            {
                hashSet.insert(temp);
                count++;
            }
        }
    }
    cout << count;

}

