#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void)
{
	int MAX_SIZE=1000000;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long int a=0;
	long long int *b = (long long int *)malloc(sizeof(long long int) *MAX_SIZE );
	
	cin>>a;
	
	for(int i=0; i<a; i++)
	{
		cin>>b[i];
	}
	int count=1;
	int sig=0;
	for(long long int i=0; i<a; i++)
	{
		if(b[i]==0||b[i]==1)
		{
			cout<<2<<'\n';
			continue;
		}
		for(long long int j=2; j*j<=b[i]; j++)
		{
			if(b[i]%j==0)
			{
				b[i]=b[i]+1;
				i--;
				sig=1;
				break;
			}
		}
		if(sig==0)
		{
			cout<<b[i]<<'\n';
		}
		sig=0;
	}
	return 0;
}