#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        queue<char> q;
    
        for(int j = 0; j < s.size(); j++)
        {
            q.push(s[j]);
        }
        
        for(int j = 0; j < i; j++)
        {
            char temp = q.front();
            q.pop();
            q.push(temp);
        }
        
        stack<char> st;
        bool sig = true;
        
        while(!q.empty())
        {
            char c = q.front();
            q.pop();
            
            if(c == '[' || c == '(' || c == '{')
            {
                st.push(c);
            }
            else if(c == ']' || c == ')' || c == '}')
            {
                if(st.empty())
                {
                    sig = false;
                    break;
                }
                if(c == ']' && st.top() != '[')
                {
                    sig = false;
                    break;
                }
                else if(c == ')' && st.top() != '(')
                {
                    sig = false;
                    break;
                }
                else if(c == '}' && st.top() != '{')
                {
                    sig = false;
                    break;
                }
                else 
                {
                    st.pop();
                }
            }
            
        }
        
        if(st.empty() && sig == true)
        {
            answer++;
        }
        
    }
    
    return answer;
}//({)} [()]