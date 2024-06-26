#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main(void)
{
	int a=0;
	
	cin>>a;
	
	int max=0;
	
	for(int i=0; i<a; i++)
	{
		cin>>arr[i];
	}
	
	sort(arr, arr+a);
	
	for(int i=0; i<a; i++)
	{
		int num=(a-i)*arr[i];
		if(num>max)
		{
			max=num;
		}
	}
	
	cout<<max;
	
	return 0;
}