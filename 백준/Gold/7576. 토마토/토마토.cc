#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001];
int visited[1001][1001];

void BFS();

int min1=10000000;

queue<int> Q;

int count1=0;

int a=0;
int b=0;
int Pcount=0;
int k=0;
int main(void)
{
	
	cin>>a>>b;
	
	for(int i=0; i<b; i++)
	{
		for(int j=0; j<a; j++)
		{
			cin>>arr[i][j];
		}
	}
	int Mcount=0;
	
	for(int i=0; i<b; i++)
	{
		for(int j=0; j<a; j++)
		{
			if(arr[i][j]==1)
			{
				count1++;
				Pcount++;
				Q.push(i);
				Q.push(j);
				Q.push(0);
			}
			else if(arr[i][j]==0)
			{
				count1++;
			}
			else if(arr[i][j]==-1)
			{
				Mcount++;
			}
		}
	}
	if(Pcount+Mcount==a*b)
	{
		cout<<0;
	}
	else
	{
		BFS();
	}
	
	
	return 0;
}
void BFS()
{
	while(!Q.empty())
	{
		int tx=Q.front();
		Q.pop();
		int ty=Q.front();
		Q.pop();
		int tcount=Q.front();
		Q.pop();
		k++;
		visited[tx][ty]=1;
		arr[tx][ty]=1;
		
		
		if(k==count1)
		{
			cout<<tcount;
			return;
		}
		tcount++;
		if(visited[tx+1][ty]==0&&tx+1>=0&&ty>=0&&tx+1<b&&ty<a&&arr[tx+1][ty]==0)
		{
			Q.push(tx+1);
			Q.push(ty);
			Q.push(tcount);
			visited[tx+1][ty]=1;
			arr[tx+1][ty]=1;
			//k++;
			
		}
		if(visited[tx-1][ty]==0&&tx-1>=0&&ty>=0&&tx-1<b&&ty<a&&arr[tx-1][ty]==0)
		{
			Q.push(tx-1);
			Q.push(ty);
			Q.push(tcount);
			visited[tx-1][ty]=1;
			arr[tx-1][ty]=1;
			//k++;
		}
		if(visited[tx][ty+1]==0&&tx>=0&&ty+1>=0&&tx<b&&ty+1<a&&arr[tx][ty+1]==0)
		{
			Q.push(tx);
			Q.push(ty+1);
			Q.push(tcount);
			visited[tx][ty+1]=1;
			arr[tx][ty+1]=1;
			//k++;
		}
		if(visited[tx][ty-1]==0&&tx>=0&&ty-1>=0&&tx<b&&ty-1<a&&arr[tx][ty-1]==0)
		{
			Q.push(tx);
			Q.push(ty-1);
			Q.push(tcount);
			visited[tx][ty-1]=1;
			arr[tx][ty-1]=1;
			//k++;
		}
		
		
	}
	cout<<-1;
}