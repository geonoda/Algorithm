#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> hashMap;
    
    for(int i = 0; i < want.size(); i++)
    {
        hashMap[want[i]] = number[i];
    }
    
    for(int i = 0; i <= discount.size() - 10; i++)
    {
        unordered_map<string, int> tempMap;
        for(int j = i; j < 10 + i; j++)
        {
            tempMap[discount[j]]++;
        }
        
        bool sig = true;
        for(auto l = hashMap.begin(); l != hashMap.end(); l++)
        {
            if(tempMap[l->first] != hashMap[l->first])
            {
                sig = false;
                break;
            }
        }
        
        if(sig == true)
        {
            answer++;
        }
    }
    
    return answer;
}// 4면  0 1 2 3 4 까지