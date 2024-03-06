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
	
	int min=0;
	int sum=0;
	int load=0;
	min=arr2[0];
	load=arr[0];
	for(int i=0; i<a-1; i++)
	{
		if(min<arr2[i+1])
		{
			load=load+arr[i+1];
		
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