#include <iostream>

using namespace std;
int arr[1000000];
int arr2[1000000];
int main(void)
{
	int a=0;
	cin>>a;
	for(int i=0; i<a-1; i++)
	{
		cin>>arr[i];
	}
	
	for(int i=0; i<a; i++)
	{
		cin>>arr2[i];
	}
	
	long long int min=0;
	long long int sum=0;
	long long int load=0;
	min=arr2[0];
	load=arr[0];
	
	for(int i=0; i<a-1; i++)
	{
		if(min<arr2[i+1]||i==a-2)
		{
			load=load+arr[i+1];
			if(i==a-2)
			{
				sum=sum+min*load;
			}
		
		}
		else
		{
			sum=sum+min*load;
			load=arr[i+1];
			min=arr2[i+1];
		}
	}
	cout<<sum;
	
	return 0;
}