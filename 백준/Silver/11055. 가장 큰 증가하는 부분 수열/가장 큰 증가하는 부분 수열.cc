#include <iostream>

using namespace std;

int arr[1001];
int DP[1001];

int main(void)
{
	int A=0;
	
	cin>>A;
	
	for(int i=0; i<A; i++)
	{
		cin>>arr[i];
		DP[i]=arr[i];
	}
	
	int max=DP[0];
	
	for(int i=0; i<A; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[i]>arr[j]&&DP[i]<DP[j]+arr[i])
			{
				DP[i]=DP[j]+arr[i];
			}
			if(DP[i]>max)
			{
				max=DP[i];
			}
		}
	}
	
	cout<<max;
}