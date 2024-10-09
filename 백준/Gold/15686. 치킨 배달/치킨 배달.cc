#include <iostream>
#include <vector>
using namespace std;

int arr[51][51];
vector<pair<int,int> > V;
int N=0;
int M=0;
int result=987654321;
void DFS(int count, int pre);
int main(void)
{
	cin>>N>>M;
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==2)
			{
				V.push_back({i,j});
			}
		}
	}
	
	DFS(0,-1);
	
	cout<<result;
	return 0;
}

int visited[50];

void DFS(int count, int pre)
{
	if(count==M)//백터에서 치킨집을 꺼내서 거리를 찾는다. 
	{
		int distance=0;
		
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				if(arr[i][j]==1)
				{
					int temp=987654321;
					for(int k=0; k<50; k++)
					{
						if(visited[k]==1)
						{
							int x=i-V[k].first;
							int y=j-V[k].second;
							if(x<0)
							{
								x=(-x);
							}
							if(y<0)
							{
								y=(-y);
							}
							if(temp>x+y)
							{
								temp=x+y;
							}
						}
					}
					distance+=temp;
				}
			}
		}
		if(distance<result)
		{
			result=distance;
		}
		
	}
	for(int i=0; i<V.size(); i++)
	{
		if(visited[i]==0&&i>pre)
		{
			visited[i]=1;
			DFS(count+1,i);
			visited[i]=0;
		}	
	}
}