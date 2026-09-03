#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Cal(string& temp, int& max, int& min);

string solution(string s) {
    string answer = "";
    
    int min = 987654321;
    int max = -987654321;
    
    int index = 0;
    string temp = "";
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            Cal(temp, max, min);
                
            temp = "";
            
            continue;
        }
        else
        {
            temp += s[i];
            
            if(i == s.size()-1)
            {
                Cal(temp, max, min);
            }
        }
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}

void Cal(string& temp1, int& max, int& min)
{
    int num = stoi(temp1);//변환
    
    if(num > max)
    {
        max = num;
    }

    if(num < min)
    {
        min = num;
    }
}