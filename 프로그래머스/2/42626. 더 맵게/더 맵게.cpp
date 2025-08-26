#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> q;

    for (int i = 0; i < scoville.size(); i++)
    {
        q.push(-scoville[i]);
    }

    while (!q.empty())
    {
        int first = -q.top();
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
        int second = -q.top();
        q.pop();  

        q.push(-(first + second * 2));

        answer++;
    }

    return answer;
}