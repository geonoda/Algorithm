#include <iostream>

using namespace std;

int DP[1001];
int DP2[1001];
int arr[1001];

int main(void)
{
	int A=0;
	
	cin>>A;
	
	for(int i=0; i<A; i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0; i<A; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[i]>arr[j]&&DP[i]<DP[j]+1)
			{
				DP[i]=DP[j]+1;
			}
		}
	}
	
	for(int i=A-1; i>=0; i--)
	{
		for(int j=A-1; j>i; j--)
		{
			if(arr[i]>arr[j]&&DP2[i]<DP2[j]+1)
			{
				DP2[i]=DP2[j]+1;
			}
		}
	}
	
	int max=0;
	for(int i=0; i<A; i++)
	{
		if(DP[i]+DP2[i]+1>max)
		{
			max=DP[i]+DP2[i]+1;
		}
	}
	
	
	cout<<max;
	
	
	
	return 0;
 } 