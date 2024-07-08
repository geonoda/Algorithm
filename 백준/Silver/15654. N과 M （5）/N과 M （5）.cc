#include <iostream>
#include <algorithm>
using namespace std;

void DFS(int stop,int visited[10]);

int arr[10];
int result[10];

int n=0;
int m=0;

int main(void)
{
    ios::sync_with_stdio(false);
  	cin.tie(NULL);
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	sort(arr,arr+n);
	int visited[10]={0};
	DFS(0,visited);
	
	return 0;
}



void DFS(int stop,int visited[10])
{	
	int temp[10];
	
	for(int i=0; i<n; i++)
	{
		for(int i=0; i<10; i++)
		{
			temp[i]=visited[i];
		}
		int k=0;
		if(visited[i]==0)
		{
			result[stop]=arr[i];
			temp[i]=1;
			k=1;
		}
		
		
		if(stop+1<m&&k==1)
		{
			DFS(stop+1,temp);
		}
		else if(k==1)
		{
			for(int i=0; i<m; i++)
			{
				cout<<result[i]<<" ";
			}
			cout<<'\n';
		}
		
	}
}