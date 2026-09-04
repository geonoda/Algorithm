#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int sum = 1;
    int start = 1;
    int end = 1;
    
    while(start <= end)
    {
        if(sum < n)
        {
            end++;
            sum += end;
        }
        else if(sum > n)
        {
            sum -= start;
            start++;
        }
        else
        {
            answer++;
            sum -= start;
            start++;
        }
        
    }
    
    return answer;
}