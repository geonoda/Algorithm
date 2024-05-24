#include <iostream>

using namespace std;

long long int DP[101][10];

int main(void)
{
	int a=0;
	cin>>a;
	
	
	for(int i=0; i<=9; i++)
	{
		DP[1][i]=1;
	}
	
	for(int i=2; i<=a; i++)
	{
		for(int j=0; j<=9; j++)
		{
			if(j-1<0)
			{
				DP[i][j]=(DP[i-1][j+1])%1000000000;
			}
			else if(j+1>9)
			{
				DP[i][j]=(DP[i-1][j-1])%1000000000;
			}
			else
			{
				DP[i][j]=(DP[i-1][j-1]+DP[i-1][j+1])%1000000000;
			}
		
		}
	}
	
	long long int sum=0;
	
	for(int i=1; i<=9; i++)
	{
		sum=(sum+DP[a][i])%1000000000;
	}
		
	cout<<sum;
	
	return 0;
}