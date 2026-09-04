#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool sig = false;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            sig = false;
            continue;
        }
        
        if(sig == false)
        {
            sig = true;
            
            if(s[i] >= 97 && s[i] <= 122)
            {
                s[i] -= 32;  
            }
        }
        else
        {
            if(s[i] >= 65 && s[i] <= 90)
            {
                s[i] += 32;  
            }
        }
    }
    
    answer = s;
    
    return answer;
}
//97, 122 a~z
//65, 90 A~Z
//48, 57 0~9