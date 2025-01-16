#include <iostream>

using namespace std;
int arr[2000][2000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	int M;
	cin>>M;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			arr[i][j]=arr[i][j]+arr[i][j-1];
		}
	}
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			arr[j][i]=arr[j][i]+arr[j-1][i];
		}
	}
	
	
	
	int x1;
	int y1; 
	int x2;
	int y2;
	
	for(int i=0; i<M; i++)
	{
		int sum=0;
		cin>>x1>>y1>>x2>>y2;
		sum=(arr[x2][y2]-arr[x1-1][y2])-(arr[x2][y1-1]-arr[x1-1][y1-1]);
		cout<<sum<<'\n';
	}
	return 0;
}