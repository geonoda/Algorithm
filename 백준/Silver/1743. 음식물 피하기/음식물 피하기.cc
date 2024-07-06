#include <iostream>

using namespace std;

int arr[101][101];

void DFS(int i, int j);

int count=0;

int N=0;
int M=0;

int main(void)
{
	
	int K=0;
	
	cin>>N>>M>>K;
	
	for(int i=0; i<K; i++)
	{
		int num1=0;
		int num2=0;
		cin>>num1>>num2;
		arr[num1][num2]=1;
	}
	
	int max=0;
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			count=0;
			if(arr[i][j]==1)
			{
				arr[i][j]=0;
				DFS(i,j);
				if(count>max)
				{
					max=count;
				}
			}
		
		}
	}
	
	cout<<max;
	
	return 0;
}

void DFS(int i, int j)
{
	count++;
	if(arr[i+1][j]==1&&i+1<=N)
	{
		arr[i+1][j]=0;
		DFS(i+1,j);
	}
	if(arr[i-1][j]==1&&i-1>0)
	{
		arr[i-1][j]=0;
		DFS(i-1,j);
	}
	if(arr[i][j+1]==1&&j+1<=M)
	{
		arr[i][j+1]=0;
		DFS(i,j+1);
	}
	if(arr[i][j-1]==1&&j-1>0)
	{
		arr[i][j-1]=0;
		DFS(i,j-1);
	}
}
