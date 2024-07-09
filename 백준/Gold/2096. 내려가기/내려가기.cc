#include <iostream>
#include <algorithm>

using namespace std;

int DP[100001][3];

int main(void)
{
	int n=0;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin>>DP[i][j];
		}
	}
	
	int max1[3]={DP[0][0],DP[0][1],DP[0][2]};
	int max2[3]={0};
	int min1[3]={DP[0][0],DP[0][1],DP[0][2]};
	int min2[3]={0};
	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<3; j++)
		{
			int max=0;
			if(max<max1[j-1]+DP[i][j]&&j-1>-1)
			{
				max=max1[j-1]+DP[i][j];
			}
			if(max<max1[j]+DP[i][j])
			{
				max=max1[j]+DP[i][j];	
			}
			if(max<max1[j+1]+DP[i][j]&&j+1<3)
			{
				max=max1[j+1]+DP[i][j];
			}
			max2[j]=max;
			
			int min=987654321;
			if(min>min1[j-1]+DP[i][j]&&j-1>-1)
			{
				min=min1[j-1]+DP[i][j];
			}
			if(min>min1[j]+DP[i][j])
			{
					min=min1[j]+DP[i][j];
			}
			if(min>min1[j+1]+DP[i][j]&&j+1<3)
			{
					min=min1[j+1]+DP[i][j];
			}
			min2[j]=min;
		}
		for(int j=0; j<3; j++)
		{
			max1[j]=max2[j];
		}
		for(int j=0; j<3; j++)
		{
			min1[j]=min2[j];
		}
	}
	
	cout<<max({max1[0], max1[1], max1[2]})<<" ";
	cout<<min({min1[0], min1[1], min1[2]})<<" ";
	
	return 0;
}