#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[100000];
int result[100000];
vector<pair<int,int> > V[1000000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<100000; i++)
	{
		result[i]=10000000;
	}
	
	int a=0;
	int b=0;
	int c=0;
	cin>>a>>b>>c;

	for(int i=0; i<b; i++)
	{
		int k1=0;
		int k2=0;
		int k3=0;
		cin>>k1>>k2>>k3;
		V[k1].push_back({k2,k3});
	}
	
	int count=0;
	visited[c]=1;
	
	priority_queue<pair<int,int> > pq;
	pq.push({0,c});
	result[c]=0;
	while(!pq.empty())
	{
		int distance=-pq.top().first;
		int current=pq.top().second;
		
		pq.pop();
		
		for(int i=0; i<V[current].size(); i++)
		{
			int next=V[current][i].first;
			int next_distance=distance+V[current][i].second;
			
			if(next_distance<result[next])
			{
				result[next]=next_distance;
				pq.push({-next_distance,next});
			}
		}
	}
	
	for(int i=1; i<=a; i++)
	{
		if(result[i]==10000000)
		{
			cout<<"INF"<<'\n';
		}
		else
		{
			cout<<result[i]<<'\n';
		}
	}
	
	return 0;
}