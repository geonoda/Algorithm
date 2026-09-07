#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Cal(int num);

int solution(int n) {
    int answer = 0;
    
    int count = Cal(n);
    
    int i = n + 1;
    while(true)
    {
        if(Cal(i) == count)
        {
            answer = i;
            break;
        }
        
        i++;
    }
    
    
    return answer;
}

int Cal(int num)
{
    int count = 0;
    while(num > 0)
    {
        if(num % 2 != 0)
        {
            count++;
        }
        num = num / 2;
    }
    
    return count;
}