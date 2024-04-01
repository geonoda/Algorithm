#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[1000][1000]={0};
int visited[1000][1000]={0};
int DFS(int x,int y);
int count1=0;
int result[1000];
int Rcount=0;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a=0;
	cin>>a;
	string k[1000];
	for(int i=0; i<a; i++)
	{
		cin>>k[i];
	}
	
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			arr[i][j]=k[i][j]-48;
		}
	}

	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			count1=0;
			count1=DFS(i,j);
			if(count1!=0)
			{
				result[Rcount]=count1;
				Rcount++;
			}
		}
	}
	sort(result,result+Rcount);
	cout<<Rcount<<'\n';
	for(int i=0; i<Rcount; i++)
	{
		cout<<result[i]<<'\n';
	}
	return 0;
}

int DFS(int x,int y)
{
	if(visited[x][y]==1)
	{
		return 0;
	}
	
	visited[x][y]=1;
	
	if(arr[x][y]!=0)
	{
		count1++;
	}
	
	if(arr[x][y]==1)
	{
		if(arr[x+1][y]==1)
		{
			DFS(x+1,y);
		}
		if(arr[x-1][y]==1)
		{
			DFS(x-1,y);
		}
		if(arr[x][y+1]==1)
		{
			DFS(x,y+1);
		}
		if(arr[x][y-1]==1)
		{
			DFS(x,y-1);
		}
	}

	return count1;
}