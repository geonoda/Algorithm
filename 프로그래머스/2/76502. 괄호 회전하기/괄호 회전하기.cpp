#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
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
            
            if(c == '[')
            {
                st.push('[');
            }
            else if(c == ']')
            {
                if(st.empty())
                {
                    sig = false;
                    break;
                }
                if(st.top() != '[')
                {
                    break;
                }
                else 
                {
                    st.pop();
                }
            }
            else if(c == '(')
            {
                st.push('(');
            }
            else if(c == ')')
            {
                if(st.empty())
                {
                    sig = false;
                    break;
                }
                if(st.top() != '(')
                {
                    break;
                }
                else 
                {
                    st.pop();
                }
            }
            else if(c == '{')
            {
                st.push('{');
            }
            else if(c == '}')
            {
                if(st.empty())
                {
                    sig = false;
                    break;
                }
                if(st.top() != '{')
                {
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