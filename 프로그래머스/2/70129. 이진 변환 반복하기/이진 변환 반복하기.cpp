#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero = 0;
    int time = 0;
    while(s.size() > 1)
    {
        time++;
        
        int count = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
            {
                zero++;
            }
            else if(s[i] == '1')
            {
                count++;
            }
        }
        s = "";
        
        while(count > 0)
        {
            if(count % 2 > 0)
            {
                s += '1';
                count = count / 2;
            }
            else
            {
                s += '0';
                count = count / 2;
            }
        }
    }
    
    answer.push_back(time);
    answer.push_back(zero);
    
    return answer;
}