#include <iostream>
#include <algorithm>

using namespace std;

int arr1[1000];
int arr2[1000];

int main(void)
{
	int a=0;
	cin>>a;
	
	for(int i=0; i<a; i++)
	{
		cin>>arr1[i];
	}
	
	for(int i=0; i<a; i++)
	{
		cin>>arr2[i];
	}
	
	sort(arr1,arr1+a);
	sort(arr2,arr2+a);
	
	int sum=0;
	
	for(int i=0; i<a; i++)
	{
		sum=sum+arr1[i]*arr2[a-1-i];
	}
	
	cout<<sum;
	
	return 0;
}