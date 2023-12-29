#include <iostream>

using namespace std;

int main(void)
{
	int a=0;
	int b=0;
	int c[10000]={0};
	
	cin>>a>>b;
	
	for(int i=0; i<a; i++)
	{
		cin>>c[i];
	}
	for(int i=0; i<a; i++)
	{
		for(int j=i; j<a; j++)
		{
			if(c[j]>c[i])
			{
				int temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}
	
	cout<<c[b-1];
	
	return 0;
}