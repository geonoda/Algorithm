#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long> q;

    for (int i = 0; i < scoville.size(); i++)
    {
        q.push(-scoville[i]);
    }

    while (!q.empty())
    {
        long long first = -q.top();
        q.pop();
        if (first >= K)
        {
            break;
        }
        if (q.empty())
        {
            answer = -1;
            break;
        }
        long long second = -q.top();
        q.pop();  

        q.push(-(first + second * 2));

        answer++;
    }

    return answer;
}