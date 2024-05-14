#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
using namespace std;

void BFS(int START, int END);

int visited[200000];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

int main(void)
{
	//fill(dist, dist+100001, -1);??
	int a=0;
	int b=0;
	
	cin>>a>>b;
	
	BFS(a,b);
	
	return 0;
}

void BFS(int START, int END)
{
	Q.push({0,START});
	
	while(!Q.empty())
	{
		int count=Q.top().first;
		int num=Q.top().second;
		Q.pop();
		
		if(num==END)
		{
			cout<<count;
			break;
		}
		
		if(visited[num*2]==0&&num*2<=100001)
		{
			Q.push({count,num*2});
			visited[num*2]=1;
		}
		if(visited[num+1]==0&&num+1>=0&&num+1<=100001)
		{
			Q.push({count+1,num+1});
			visited[num+1]=1;
		}
		if(visited[num-1]==0&&num-1>=0&&num-1<=100001)
		{
			Q.push({count+1,num-1});
			visited[num-1]=1;
		}	
	}
}