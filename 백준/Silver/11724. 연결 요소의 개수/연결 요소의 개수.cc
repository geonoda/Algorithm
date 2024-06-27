#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
int visited[1001];

void DFS(int a);

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
		
		v[num1].push_back(num2);
		v[num2].push_back(num1);
	}
	
	int count=0;
	
	for(int i=1; i<=a; i++)
	{
		if(visited[i]==0)
		{
			visited[i]=1;
			DFS(i);
			count++;
		}
		
	}
	
	cout<<count;
	
	
	return 0;
}

void DFS(int a)
{
	for(int i=0; i<v[a].size(); i++)
	{
		if(visited[v[a][i]]==0)
		{
			visited[v[a][i]]=1;
			DFS(v[a][i]);
		}
	}
}