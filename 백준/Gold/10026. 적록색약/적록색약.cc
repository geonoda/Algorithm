#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int> > Q;

int arr[101][101];

int visited[101][101];

void BFS(int val);

int a=0;

int main(void)
{

	cin>>a;
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			char k;
			cin>>k;
			if(k=='R')
			{
				arr[i][j]=0;
			}
			else if(k=='G')
			{
				arr[i][j]=1;
			}
			else
			{
				arr[i][j]=2;
			}
		}
	}
	
	int count=0;
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			if(visited[i][j]==0)
			{
				Q.push(make_pair(i,j));
				visited[i][j]=1;
				BFS(arr[i][j]);
				count++;
			}	
		}
	}
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			visited[i][j]=0;
			if(arr[i][j]==1)
			{
				arr[i][j]=0;
			}
		}
	}
	
	int count2=0;
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			if(visited[i][j]==0)
			{
				Q.push(make_pair(i,j));
				visited[i][j]=1;
				BFS(arr[i][j]);
				count2++;
			}	
		}
	}
	
	cout<<count<<" "<<count2;
	
	return 0;
}

void BFS(int val)
{
	while(!Q.empty())
	{
		int i=Q.front().first;
		int j=Q.front().second;
		Q.pop();
		
		if(arr[i+1][j]==val&&visited[i+1][j]==0&&i+1<a)
		{
			visited[i+1][j]=1;
			Q.push(make_pair(i+1,j));
		}
		if(arr[i-1][j]==val&&visited[i-1][j]==0&&i-1>-1)
		{
			visited[i-1][j]=1;
			Q.push(make_pair(i-1,j));
		}
		if(arr[i][j+1]==val&&visited[i][j+1]==0&&j+1<a)
		{
			visited[i][j+1]=1;
			Q.push(make_pair(i,j+1));
		}
		if(arr[i][j-1]==val&&visited[i][j-1]==0&&j-1>-1)
		{
			visited[i][j-1]=1;
			Q.push(make_pair(i,j-1));
		}
		
	}
}