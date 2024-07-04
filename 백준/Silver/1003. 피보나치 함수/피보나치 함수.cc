#include <iostream>

using namespace std;

int DP[41][2];

int fibonacci(int n);

int main(void)
{
	int a=0;
	cin>>a;
	
	DP[0][0]=1;
	DP[0][1]=0;
	DP[1][0]=0;
	DP[1][1]=1;
	
	for(int i=2; i<=40; i++)
	{
		DP[i][0]=DP[i-1][0]+DP[i-2][0];
		DP[i][1]=DP[i-1][1]+DP[i-2][1];
	}
	
	for(int i=0; i<a; i++)
	{
		int num=0;
		cin>>num;
		cout<<DP[num][0]<<" "<<DP[num][1]<<endl;
	}
	
	fibonacci(5);
	return 0;
}

int fibonacci(int n)
{
    if (n == 0) {
        //printf("0");
        return 0;
    } else if (n == 1) {
        //printf("1");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}