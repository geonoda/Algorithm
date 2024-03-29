#include <iostream>

using namespace std;

int arr[500][2]={0};
int dp[501][501]={0};
int main(void)
{
	int a=0;
	cin>>a;
	for(int i=1; i<=a; i++)
	{
		cin>>arr[i][0];
		cin>>arr[i][1];
	}
	
	for(int d=1; d<a; d++)
	{
		for(int x=1; x+d<=a; x++)
		{
			int y=x+d;
			dp[x][y]=1000000000;
			for(int mid=x; mid<y; mid++)
			{
				int num=dp[x][mid]+dp[mid+1][y]+arr[x][0]*arr[mid][1]*arr[y][1];
				if(num<dp[x][y])
				{
					dp[x][y]=num;
				}
			}
		}
	}
	cout<<dp[1][a];
	
	return 0;
}