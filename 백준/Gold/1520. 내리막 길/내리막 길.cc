#include <iostream>

using namespace std;
int arr[1000][1000];
int dp[1000][1000]={0};
int re(int x, int y);
int a=0;
int b=0;
int count1=0;
int main(void)
{
	
	cin>>a>>b;
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			cin>>arr[i][j];
			dp[i][j]=-1;
		}
	}
	cout<<re(0,0);
	return 0;
}
int re(int x, int y)
{
	int sig=0;
	if(x==a-1&&y==b-1)
	{
		return 1;
	}
	if(dp[x][y]!=-1)
	{
		return dp[x][y];
	}
	dp[x][y]=0;
	if(dp[x][y]==0)
	{
		if(arr[x][y]>arr[x+1][y])
		{
			if(x+1<a)
			{
				sig=1;
				dp[x][y]=dp[x][y]+re(x+1,y);
			}
			
		}
		if(arr[x][y]>arr[x-1][y])
		{
			if(x-1>=0)
			{
				sig=1;
				dp[x][y]=dp[x][y]+re(x-1,y);
			}
			
		}
		if(arr[x][y]>arr[x][y+1])
		{
			if(y+1<b)
			{
				sig=1;
				dp[x][y]=dp[x][y]+re(x,y+1);
			}
			
		}
		if(arr[x][y]>arr[x][y-1])
		{
			if(y-1>=0)
			{
				sig=1;
				dp[x][y]=dp[x][y]+re(x,y-1);
			}
		}
	}
	
	return dp[x][y];
}