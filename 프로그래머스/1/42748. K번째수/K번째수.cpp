#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{

    return 0;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        vector<int>temp;
        int start = commands[i][0];
        int end = commands[i][1];
        int index = commands[i][2];

        for (int i = start - 1; i < end; i++)
        {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());

        answer.push_back(temp[index - 1]);

    }



    return answer;
}