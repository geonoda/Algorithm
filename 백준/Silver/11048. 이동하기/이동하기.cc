#include <iostream>

using namespace std;

int DP[1001][1001];

int main(void)
{
	int N=0;
	int M=0;
	
	cin>>N>>M;
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			cin>>DP[i][j];
		}
	}
	
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			int max=0;
			if(DP[i-1][j-1]>max&&i-1>0&&j-1>0)
			{
				max=DP[i-1][j-1];
			}
			if(DP[i-1][j]>max&&i-1>0)
			{
				max=DP[i-1][j];
			}
			if(DP[i][j-1]>max&&j-1>0)
			{
				max=DP[i][j-1];
			}
			DP[i][j]+=max;	
		}
	}
	cout<<DP[N][M];
	return 0;
}