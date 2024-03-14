#include <iostream>
#include <algorithm>
using namespace std;

long long int arr1[100001]={0};
long long int arr2[100001]={0};

int main(void)
{
	int a;
	int b;
	cin>>a;
	for(int i=0; i<a; i++)
	{
		cin>>arr1[i];
	}
	cin>>b;
	for(int i=0; i<b; i++)
	{
		cin>>arr2[i];
	}
	
	sort(arr1,arr1+a);
	
	for(int i=0; i<b; i++)
	{
		int L=0;
		int R=a-1;
		int mid=0;
		int sig=0;
		while(L<=R)
		{
			mid=(L+R)/2;
			if(arr2[i]<arr1[mid])
			{
				R=mid-1;
			}
			else if(arr2[i]>arr1[mid])
			{
				L=mid+1;
				
			}
			else if(arr2[i]==arr1[mid])
			{
				sig=1;
				break;
			}
			
			
		}
		if(sig==1)
		{
			cout<<1<<'\n';
		}
		else
		{
			cout<<0<<'\n';
		}
	}
	
	return 0;
}