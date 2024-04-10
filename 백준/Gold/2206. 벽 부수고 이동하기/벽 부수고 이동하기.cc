#include <iostream>
#include <queue>

using namespace std;

queue<int> Q;

int arr[1001][1001];
int visited[1001][1001][2];
int a=0;
int b=0;

void BFS();

int main(void)
{

	cin>>a>>b;
	string s[1001];

	for(int i=1; i<=a; i++)
	{
		cin>>s[i];
	}
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=b; j++)
		{
			arr[i][j]=s[i][j-1]-48;
		}
	}
	BFS();
	
	
	return 0;
}

void BFS()
{
	
	Q.push(1);
	Q.push(1);
	Q.push(1);
	Q.push(1);

	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		int y=Q.front();
		Q.pop();
		int count=Q.front();
		Q.pop();
		int sig=Q.front();
		Q.pop();
		if(x==a&&y==b)
		{
			cout<<count;
			return;
		}
		
		for(int i=-1; i<2; i=i+2)
		{
			if(sig>0)
			{
				int k=sig;
				if(visited[x+i][y][0]==0&&x+i>=1&&x+i<=a)
				{
					if(arr[x+i][y]==1)
					{
						k--;
					}
					visited[x+i][y][0]=1;
					visited[x+i][y][1]=1;
					Q.push(x+i);
					Q.push(y);
					Q.push(count+1);
					Q.push(k);
				}
			}
			else
			{
				if(visited[x+i][y][1]==0&&x+i>=1&&x+i<=a&&arr[x+i][y]==0)
				{
					visited[x+i][y][1]=1;
					Q.push(x+i);
					Q.push(y);
					Q.push(count+1);
					Q.push(sig);
				}
			}
			
		}
		for(int i=-1; i<2; i=i+2)
		{
			if(sig>0)
			{
				int k=sig;
				if(visited[x][y+i][0]==0&&y+i>=1&&y+i<=b)
				{
					if(arr[x][y+i]==1)
					{
						k--;
					}
					visited[x][y+i][0]=1;
					visited[x][y+i][1]=1;
					Q.push(x);
					Q.push(y+i);
					Q.push(count+1);
					Q.push(k);
				}
			}
			else
			{
				if(visited[x][y+i][1]==0&&y+i>=1&&y+i<=b&&arr[x][y+i]==0)
				{
					visited[x][y+i][1]=1;
					Q.push(x);
					Q.push(y+i);
					Q.push(count+1);
					Q.push(sig);
				}
			}
		}
		
	}
	cout<<-1;
	
}