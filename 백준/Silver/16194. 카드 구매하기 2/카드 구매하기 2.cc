#include <iostream>

using namespace std;

int arr[1001];

int DP[1001][1001];

int main(void)
{
	int N=0;
	
	cin>>N;
	
	for(int i=1; i<=N; i++)
	{
		cin>>arr[i];
	}
	
	for(int i=1; i<=N; i++)
	{
		DP[1][i]=arr[1]*i;
	}
	
	for(int i=2; i<=N; i++)
	{
		for(int j=1; j<=N; j++)
		{
			DP[i][j]=DP[i-1][j];
			if(j/i>=1)
			{
				if(DP[i][j]>DP[i][j-i]+arr[i])
				{
					DP[i][j]=DP[i][j-i]+arr[i];
				}
			}
		}
	}
	
	cout<<DP[N][N];
	
	return 0;
}