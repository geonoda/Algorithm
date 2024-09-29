#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int> hashMap;

    int N = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string temp = "";
        cin >> temp;
        hashMap[temp] = i;
    }

    int count = 0;
    for (int i = 0; i < N; i++)//자기를 추월했다면?? 자기보다 앞에 있는 차가 다른 다른 추월하는 것은 자신의 순서에 영향을 미치지 않는다.
    {
        string temp = "";
        cin >> temp;
        if (hashMap[temp] > i)
        {
            int sig = 0;
            for (const auto& pair : hashMap) 
            {
                if (pair.second < hashMap[temp])
                {
                    hashMap[pair.first]++;
                    sig = 1;
                }
            }
            if (sig == 1)
            {
                count++;
            }
        }
    }

    cout << count;
    
}