#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321;

using namespace std;

vector<pair<int,int> > V[1001];
priority_queue<pair<int,int> > Q;
int arr[1001];

int main(void)
{
	int N=0;
	int M=0;
	
	cin>>N>>M;
	
	for(int i=0; i<M; i++)
	{
		int num1=0;
		int num2=0;
		int num3=0;
		cin>>num1>>num2>>num3;
		
		V[num1].push_back(make_pair(num2,num3));
	}
	
	int start=0;
	int end=0;
	cin>>start>>end;
	
	Q.push(make_pair(0,start));
	
	if(start==end)
	{
		cout<<0;
		return 0;
	}
	
	for(int i=1; i<1001; i++)
	{
		arr[i]=INF;
	}
	
	arr[start]=0;
	
	while(!Q.empty())
	{
		int distance=-Q.top().first;
		int current=Q.top().second;
		Q.pop();
		
		if(distance>arr[current])
		{
			continue;
		}
		
		for(int i=0; i<V[current].size(); i++)
		{
			int next=V[current][i].first;
			int newdistance=distance+(V[current][i].second);
			
			if(newdistance<arr[next])
			{
				arr[next]=newdistance;
				Q.push(make_pair(-newdistance,next));
			}
		}
	}
	
	cout<<arr[end];
	
	return 0;
} 