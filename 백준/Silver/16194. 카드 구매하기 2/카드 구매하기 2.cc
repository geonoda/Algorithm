#include <iostream>

using namespace std;

int arr[1001];
int DP[1001];

int main(void)
{
	int a=0;
	
	cin>>a;
	
	for(int i=1; i<=a; i++)
	{
		cin>>arr[i];
		DP[i]=987654321;
	}
	
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=a; j++)
		{
			if(i-j>=0)
			{
				if(DP[i]>arr[j]+DP[i-j])
				{
					DP[i]=arr[j]+DP[i-j];
				}
				
			}
			else
			{
				break;
			}
		}
	}
	
	cout<<DP[a];
	
	return 0;
}