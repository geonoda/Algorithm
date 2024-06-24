#include <iostream>

using namespace std;

int DP[1000][2];

int main(void)
{
	int a=0;
	cin>>a;
	
	for(int i=1; i<=a; i++)
	{
		int num=0;
		cin>>num;
		DP[i][0]=num;
		DP[i][1]=num;
	}
	
	
	for(int i=2; i<=a; i++)
	{
		DP[i][0]=DP[i-1][1]+DP[i][0];
		
		if(DP[i-2][0]>DP[i-2][1])
		{
			DP[i][1]=DP[i-2][0]+DP[i][1];
		}
		else
		{
			DP[i][1]=DP[i-2][1]+DP[i][1];
		}
	}
	
	if(DP[a][0]>DP[a][1])
	{
		cout<<DP[a][0];
	}
	else
	{
		cout<<DP[a][1];
	}

	return 0;
}