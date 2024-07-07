#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int,int> > Q;

int main(void)
{
	int n=0;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int a=0;
		int start=0;
		int end=0;
		cin>>a>>start>>end;
		Q.push(make_pair(-start,end));
	}
	
	priority_queue<int> Q2;
	Q2.push(0);
	int count=1;
	while(!Q.empty())
	{
		
		int start=-Q.top().first;
		int end=Q.top().second;
		Q.pop();
		
		if(-Q2.top()>start)
		{
			count++;
			Q2.push(-end);
		}
		else
		{
			Q2.push(-end);
			Q2.pop();
		}
	}
	
	cout<<count;
	
	return 0;
}