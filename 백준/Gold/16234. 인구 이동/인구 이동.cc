#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

int arr[101][101];
int visited[101][101];
int started[101][101];

int N=0;
int L=0;
int R=0;
int continue1=0;

void BFS(int i, int j, int count);

int main(void)
{
	cin>>N>>L>>R;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>arr[i][j];
			started[i][j]=1;
		}
	}
	
	int count=0;
	while(true)
	{
		count++;
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(started[i][j]==1)
				{
					BFS(i,j,i*N+j+1);
				}
				
			}
		}
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(visited[i][j]==0)
				{
					started[i][j]=0;
				}
				else
				{
					started[i][j]=1;
					visited[i][j]=0;
				}
				
			}
		}
		
		/*for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				cout<<started[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/
		
		if(continue1==0)
		{
			count--;
			break;
		}
		continue1=0;
	}
	cout<<count;
	
	
	return 0;
}

void BFS(int si, int sj, int count)
{
	queue<pair<int,int> > Q;
	Q.push(make_pair(si,sj));
	
	int sum=0;
	int k=0;
	
	while(!Q.empty())
	{
		int i=Q.front().first;
		int j=Q.front().second;
		Q.pop();
		if(abs(arr[i][j]-arr[i][j-1])>=L&&abs(arr[i][j]-arr[i][j-1])<=R&&visited[i][j-1]==0&&j-1>-1)
		{
			visited[i][j-1]=count;
			started[i][j-1]=count;
			sum+=arr[i][j-1];
			k++;
			Q.push(make_pair(i,j-1));
			
		}
		if(abs(arr[i][j]-arr[i][j+1])>=L&&abs(arr[i][j]-arr[i][j+1])<=R&&visited[i][j+1]==0&&j+1<N)
		{
			visited[i][j+1]=count;
			started[i][j+1]=count;
			sum+=arr[i][j+1];
			k++;
			Q.push(make_pair(i,j+1));
		}
		if(abs(arr[i][j]-arr[i-1][j])>=L&&abs(arr[i][j]-arr[i-1][j])<=R&&visited[i-1][j]==0&&i-1>-1)
		{
			visited[i-1][j]=count;
			started[i-1][j]=count;
			sum+=arr[i-1][j];
			k++;
			Q.push(make_pair(i-1,j));
		}
		if(abs(arr[i][j]-arr[i+1][j])>=L&&abs(arr[i][j]-arr[i+1][j])<=R&&visited[i+1][j]==0&&i+1<N)
		{
			visited[i+1][j]=count;
			started[i+1][j]=count;
			sum+=arr[i+1][j];
			k++;
			Q.push(make_pair(i+1,j));
		}
	}
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(visited[i][j]==count)
			{
				continue1=1;
				arr[i][j]=sum/k;
			}
		}
	}
}