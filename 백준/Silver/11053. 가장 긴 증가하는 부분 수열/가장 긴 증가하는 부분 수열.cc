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
	}
	
	int max=0;
	
	for(int i=0; i<A; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[i]>arr[j])
			{
				if(DP[i]<DP[j]+1)
				{
					DP[i]=DP[j]+1;
				}
				if(DP[i]>max)
				{
					max=DP[i];
				}
			}
		}
	}
	
	cout<<max+1;
	
	
	return 0;
}