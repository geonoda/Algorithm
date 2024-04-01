#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int>V[101];
int result=0;
int visited[101];

void DFS(int R);

int main(void)
{
	int a=0;
	int b=0;
	cin>>a>>b;
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
	
	DFS(1);
	
	cout<<result;
	
	return 0;
}

void DFS(int R)
{
	visited[R]=1;
	
	for(int i=0; i<V[R].size(); i++)
	{
		int temp=V[R][i];
		if(visited[temp]==0)
		{
			result++;
			visited[temp]=1;
			DFS(temp);
		}
	}
}