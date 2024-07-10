#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int arr[21][21];

void BFS(int SL, int SC);

int N=0;

int main(void)
{
	cin>>N;
	
	int SL=0;
	int SC=0;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==9)
			{
				SL=i;
				SC=j;
				arr[i][j]=0;
			}
		}
	}
	
	BFS(SL,SC);
	
	return 0;
}

void BFS(int SL, int SC)
{
	queue<pair<int,int> > Q;
	queue<int> Q2;
	Q.push(make_pair(SL,SC));
	Q2.push(0);
	
	int level=2;
	int eat=0;
	
	int visited[21][21]={0};
	
	priority_queue<pair<int,int>> minQ;
	
	int sum=0;
	
	int min=INF;
	int tempi=INF;
	int tempj=INF;
	
	while(!Q.empty())
	{
		int i=Q.front().first;
		int j=Q.front().second;
		Q.pop();
		int distance=Q2.front();
		Q2.pop();
		
		visited[i][j]=1;
		
		if(arr[i][j]>0&&arr[i][j]<level)
		{
			if(min>=distance)
			{
				min=distance;
				if(i<tempi)
				{
					tempi=i;
					tempj=j;
				}
			}
		}
		else
		{
			if(visited[i-1][j]==0&&arr[i-1][j]<=level&&i-1>-1)
			{
				visited[i-1][j]=1;
				Q.push(make_pair(i-1,j));
				Q2.push(distance+1);
			}
			if(visited[i][j-1]==0&&arr[i][j-1]<=level&&j-1>-1)
			{
				visited[i][j-1]=1;
				Q.push(make_pair(i,j-1));
				Q2.push(distance+1);
			}
			if(visited[i+1][j]==0&&arr[i+1][j]<=level&&i+1<N)
			{
				visited[i+1][j]=1;
				Q.push(make_pair(i+1,j));
				Q2.push(distance+1);
			}
			
			if(visited[i][j+1]==0&&arr[i][j+1]<=level&&j+1<N)
			{
				visited[i][j+1]=1;
				Q.push(make_pair(i,j+1));
				Q2.push(distance+1);
			}
		}
		
		if(Q.empty())
		{
			if(min!=INF)
			{
				eat++;
				arr[tempi][tempj]=0;
				sum=sum+min;
				for(int l=0; l<21; l++)
				{
					for(int k=0; k<21; k++)
					{
						visited[l][k]=0;
					}
				}
				while(!Q.empty())
				{
					Q.pop();
					Q2.pop();
				}
				Q.push(make_pair(tempi,tempj));
				Q2.push(0);
				min=INF;
				tempi=INF;
				tempj=INF;
				if(eat==level)
				{
					level++;
					eat=0;
				}
			}
		}
		
		
		
	}
	
	cout<<sum;
	
}