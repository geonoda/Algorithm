#include <iostream>

using namespace std;

int main(void)
{
	int k[10000];
	int count;
	cin>>count;
	for(int i=0; i<count; i++)
	{
		cin>>k[i];
	}
	for(int i=0; i<count; i++)
	{
		int a=k[i]/25;
		k[i]=k[i]%25;
		int b=k[i]/10;
		k[i]=k[i]%10;
		int c=k[i]/5;
		k[i]=k[i]%5;
		int d=k[i]/1;
		k[i]=k[i]%1;
		
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	}
	
	
	
	
	
	return 0;
}