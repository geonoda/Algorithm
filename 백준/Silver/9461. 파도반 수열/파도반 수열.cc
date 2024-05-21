#include <iostream>

using namespace std;

long long int sol(int num);

long long int DP[101];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a=0;
	cin>>a;
	DP[0]=1;
	DP[1]=1;
	DP[2]=1;
	for(int i=0; i<a; i++)
	{
		int b=0;
		cin>>b;
		cout<<sol(b-1)<<'\n';
	}
	return 0;
}

long long int sol(int num)
{
	 if(num==0||num==1||num==2)
	 {
	 	return 1;
	 }
	 else
	 {
	 	if(DP[num-2]==0)
	 	{
	 		DP[num-2]=sol(num-4)+sol(num-5);
		 }
		if(DP[num-3]==0)
		{
			DP[num-3]=sol(num-5)+sol(num-6);
		}
		
	 	return DP[num-2]+DP[num-3];
	 }
}