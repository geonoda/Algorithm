#include <iostream>

using namespace std;

int DP[1000001];

int main(void)
{
	int N=0;
	
	cin>>N;
	
	for(int i=2; i<=N; i++)
	{
		int max=987654321;
	
		if(DP[i/3]+1<max&&i%3==0)
		{
			max=DP[i/3]+1;
		}
		if(DP[i/2]+1<max&&i%2==0)
		{
			max=DP[i/2]+1;
		}
		if(DP[i-1]+1<max)
		{
			max=DP[i-1]+1;
		}
		DP[i]=max;
	}
	
	cout<<DP[N]<<endl;
	
	cout<<N<<" ";
	
	if(N==1)
	{
		return 0;
	}
	
	int i=N;
	while(true)
	{
		int max=987654321;
		int next=0;
		
		if(DP[i-1]<max)
		{
			max=DP[i-1];
			next=i-1;
		}
		if(DP[i/2]<max&&i%2==0)
		{
			max=DP[i/2];
			next=i/2;
		}
		if(DP[i/3]<max&&i%3==0)
		{
			max=DP[i/3];
			next=i/3;
		}
		
		cout<<next<<" ";
		i=next;
		
		if(next==1)
		{
			break;
		}
	}
	
	
	
	return 0;
}