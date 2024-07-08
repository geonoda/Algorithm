#include <iostream>

using namespace std;

int main(void)
{
	int a=0;
	
	cin>>a;
	
	for(int l=0; l<a; l++)
	{
		int n=0;
		cin>>n;
		
		int arr[2][100001]={0};
		int DP[2][100001]={0};
		
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin>>arr[i][j];
			}
		}
		
		DP[0][0]=arr[0][0];
		DP[1][0]=arr[1][0];
		DP[0][1]=DP[1][0]+arr[0][1];
		DP[1][1]=DP[0][0]+arr[1][1];
		
		int max=0;
		
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				if(DP[i][j]>max)
				{
					max=DP[i][j];
				}
			}
		}
		
		
		
		
		for(int i=2; i<n; i++)
		{
			if(DP[0][i-2]>DP[0][i-1])
			{
				DP[1][i]=arr[1][i]+DP[0][i-2];
			}
			else
			{
				DP[1][i]=arr[1][i]+DP[0][i-1];
			}
			
			if(DP[1][i-2]>DP[1][i-1])
			{
				DP[0][i]=arr[0][i]+DP[1][i-2];
			}
			else
			{
				DP[0][i]=arr[0][i]+DP[1][i-1];
			}
			
			if(DP[0][i]>max)
			{
				max=DP[0][i];
			}
			if(DP[1][i]>max)
			{
				max=DP[1][i];
			}
		}
		
		cout<<max<<'\n';
	}
	
	
	return 0;
}