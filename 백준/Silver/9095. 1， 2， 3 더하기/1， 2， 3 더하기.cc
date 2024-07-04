#include <iostream>

using namespace std;

int DP[12];

int main(void)
{
	int a=0;
	cin>>a;
	DP[1]=1;
	DP[2]=2;
	DP[3]=4;
	
	for(int i=4; i<12; i++)
	{
		DP[i]=DP[i-1]+DP[i-2]+DP[i-3];
	}
	
	for(int i=0; i<a; i++)
	{
		int num=0;
		cin>>num;
		cout<<DP[num]<<endl;
	}
	
	return 0;
}