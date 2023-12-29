#include <iostream>

using namespace std;

int main(void)
{
	int a[5];
	int sum=0;
	for(int i=0; i<5; i++)
	{
		cin>>a[i];
		sum=sum+a[i];
	}
	
	int min=100000;
	
	for(int i=0; i<5; i++)
	{
		for(int j=i; j<5; j++)
		{
			if(a[j]<a[i])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			
		}
	}
	int av=0;
	int mid=0;
	
	cout<<sum/5<<endl;
	cout<<a[2];
	
	return 0;
}