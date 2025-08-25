#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int start = 0;
    int time = 1;
    while (true)
    {
        if (start > progresses.size() - 1)
        {
            break;
        }

        if (progresses[start] + speeds[start]*time >= 100)
        {
            int k = 1;

            while (true)
            {
                start++;

                if (start > progresses.size() - 1)
                {
                    answer.push_back(k);
                    break;
                }

                if (progresses[start] + speeds[start] * time >= 100)
                {
                    k++;
                }
                else
                {
                    answer.push_back(k);
                    break;
                }
            }
        }
        else
        {
            time++;
        }
        
    }

    return answer;
}