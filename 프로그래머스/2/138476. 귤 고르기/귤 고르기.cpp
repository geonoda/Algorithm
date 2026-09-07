#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int,int> map;
    priority_queue<pair<int,int>> pq;
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        map[tangerine[i]]++;
    }
    
    for(auto i = map.begin(); i != map.end(); i++)
    {
        pq.push({-i->second, i->first});
    }
    
    int count = tangerine.size();
    
    while(!pq.empty())
    {
        int num = -pq.top().first;
        pq.pop();
        
        count = count - num;
        if(count == k)
        {
            break;
        } 
        else if(count < k)
        {
            answer++;
            break;
        }
    }
    
    while(!pq.empty())
    {
        pq.pop();
        answer++;
    }
    
    return answer;
}