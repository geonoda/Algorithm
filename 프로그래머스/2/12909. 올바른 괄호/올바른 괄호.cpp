#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int count = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            count++;
        }
        else if(s[i] == ')')
        {
            count --;
        }
        
        if(count < 0)
        {
            answer = false;
            break;
        }
    }
    
    if(count > 0)
    {
        answer = false;
    }

    return answer;
}