#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    if(b < a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while(true)
    {
        answer++;
        
        if(abs(a - b) == 1 && a % 2 == 1)
        {
            break;
        }
        
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        
    }

    return answer;
}
// 1 2 3 4 5 6