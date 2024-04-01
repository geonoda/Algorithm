#include <iostream>
#include <queue>
#include <algorithm>

int visited[100001];
using namespace std;
int BFS(int R);
vector<int> V[100001];
int result[100001];
queue<int> Q;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a=0;
	int b=0;
	int c=0;
	cin>>a>>b>>c;
	for(int i=0; i<b; i++)
	{
		int num1=0;
		int num2=0;
		cin>>num1>>num2;
		V[num1].push_back(num2);
		V[num2].push_back(num1);
	}
	
	
	for(int i=1; i<=a; i++)
	{
		sort(V[i].begin(),V[i].end());
	}
	
	BFS(c);
	
	for(int i=1; i<=a; i++)
	{
		cout<<result[i]<<'\n';
	}
	
	return 0;
}

int BFS(int R)
{
	int count=0;
	
	visited[R]=1;
	count++;
	result[R]=count;
	
	Q.push(R);
	while(!Q.empty())
	{
		int k=Q.front();
		Q.pop();
		for(int i=0; i<V[k].size(); i++)
		{
			int temp=V[k][i];
			if(visited[temp]==0)
			{
				visited[temp]=1;
				count++;
				result[temp]=count;
				Q.push(temp);
			}
		}
	}
	return 0;
}