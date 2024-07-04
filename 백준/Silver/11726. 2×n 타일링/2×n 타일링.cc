#include <iostream>

using namespace std;

int DP[1001];

int main(void)
{
	int a=0;
	cin>>a;
	
	DP[1]=1;
	DP[2]=2;
	
	for(int i=3; i<=1000; i++)
	{
		DP[i]=(DP[i-1]+DP[i-2])%10007;
	}
	
	cout<<DP[a];
	
	return 0;
}