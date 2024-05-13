#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int> > V[100000];


int sol(int S, int E);

int v1=0;
int v2=0;
	
int main(void)
{
	int v=0;
	int e=0;
	
	cin>>v>>e;
	
	for(int i=0; i<e; i++)
	{
		int a=0;
		int b=0;
		int c=0;
		cin>>a>>b>>c;
		V[a].push_back({b,c});
		V[b].push_back({a,c});

	}
	
	
	cin>>v1>>v2;
	
	int num1=sol(1,v1);
	int num2=sol(1,v2);
	
	int num3=sol(v1,v2);
	
	int num4=sol(v1,v);
	int num5=sol(v2,v);
	
	int result=num1+num3+num5;
	
	if(result>num2+num3+num4)
	{
		result=num2+num3+num4;
	}
	
	if(result>=987654321||num3==987654321)
	{
		cout<<-1;
	}
	else
	{
		cout<<result;
	}
	return 0;
}
int sol(int S,int E)
{
	int D[100000];
	for(int i=0; i<100000; i++)
	{
		D[i]=987654321;
	}
	priority_queue<pair<int,int> > pq;
	pq.push({0,S});
	D[S]=0;

	while(!pq.empty())
	{
		int dis=-pq.top().first;
		int cur=pq.top().second;
		
		pq.pop();
		
		int sig=0;
		for(int i=0; i<V[cur].size(); i++)
		{
			int next=V[cur][i].first;
			int nextdis=dis+V[cur][i].second;
			
			if(nextdis<D[next])
			{
				D[next]=nextdis;
				pq.push({-D[next],next});
			}
		}
	}
	return D[E];
}