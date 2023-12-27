#include <iostream>

using namespace std;

int main(void)
{
	int a;
	cin>>a;
	
	int k=2;
	for(int i=0; i<a; i++)
	{
		k=k+(k-1);
	}
	cout<<k*k;
	return 0;
}