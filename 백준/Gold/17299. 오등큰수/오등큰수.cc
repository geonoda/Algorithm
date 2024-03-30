#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001]={0};
int arr2[1000001]={0};
int arr3[1000001]={0};
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int a=0;
	cin>>a;
	int max=0;
	for(int i=0; i<a; i++)
	{
		cin>>arr[i];
		arr2[arr[i]]++;
		if(max<arr2[arr[i]])
		{
			max=arr2[arr[i]];
		}
	}
	                                                                                                                                                                                                                             
	
	for(int i=0; i<a; i++)
	{
		int k=arr2[arr[i]];
		int j=i;
		while(true)
		{
			if(k>=max)
			{
				cout<<-1<<" ";
				break;
			}
			j++;
			if(k<arr2[arr[j]])
			{
				cout<<arr[j]<<" ";
				break;
			}
			if(j>a)
			{
				cout<<-1<<" ";
				break;
			}
		}
	}
	
	return 0;
}