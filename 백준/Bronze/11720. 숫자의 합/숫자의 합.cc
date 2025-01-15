#include <iostream>

using namespace std;

int main(void)
{
	string n;
	int k;
	cin>>k;
	int sum=0;
	cin>>n;
	
	for(int i=0; i<k; i++)
	{
		sum=sum+n[i]-48;
	}
	cout<<sum;
	return 0;
}