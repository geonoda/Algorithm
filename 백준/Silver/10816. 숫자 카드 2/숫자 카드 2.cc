#include <iostream>
#include <algorithm>
using namespace std;

int arr1[500001]={10000001};
int result[500001]={0};
int arr2[500002]={0};

int main(void)
{
	int a=0;
	int b=0;
	for(int i=0; i<500001; i++)
	{
		arr1[i]=10000001;
	}
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

	for(int i=0; i<a; i++)
	{
		int j=i;
		while(true)
		{
			j++;
			if(arr1[i]==arr1[j])
			{
				result[i]=result[i]+1;
				result[j]=result[i];
				
			}
			else
			{
				for(int k=i; k<j; k++)
				{
					result[k]=result[i];
				}
				i=j-1;
				break;
			}
		}
		
	}
	for(int i=0; i<b; i++)
	{
		int L=0;
		int R=a-1;
		int mid=0;
		int sig=0;
		int count=0;
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
			int k=result[mid]+1;
		
			cout<<k<<" ";
		}
		else
		{
			cout<<0<<" ";
		}
	}
	
	
	
	return 0;
}