#include <iostream>

using namespace std;

long long int re(int a, int b, int c);

int main(void)
{
	int a,b,c=0;
	cin>>a>>b>>c;
	cout<<re(a,b,c);
	return 0;
}

long long int re(int a, int b, int c)
{
	if(b==0)
	{
		return 1;
	}
	long long int temp=re(a,b/2,c);
	temp=temp*temp%c;
	if(b%2==0)
	{
		return temp;
	}
	else
	{
		return temp*a%c;
	}
}