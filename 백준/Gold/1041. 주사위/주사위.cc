#include <iostream>

using namespace std;

int arr[6];

int main(void)
{
	long long int a=0;
	long long int min1=1000;
	long long int min2=1000;
	long long int min3=1000;
	
	cin>>a;
	
	for(int i=0; i<6; i++)
	{
		cin>>arr[i];
		if(arr[i]<min1)
		{
			min1=arr[i];
		}
	}
	
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(i!=j&&j!=5-i)
			{
				if(arr[i]+arr[j]<min2)
				{
					min2=arr[i]+arr[j];
				}
			}
		}
	}
	
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(i!=j&&j!=5-i)
			{
				for(int l=0; l<6; l++)
				{
					if(l!=j&&l!=i&&l!=5-j&&l!=5-i)
					{
						if(min3>arr[i]+arr[j]+arr[l])
						{
							min3=arr[i]+arr[j]+arr[l];
						}
					}
				}
			}
		}
	}
	
	
	long long int result=((a-1)*(a-2)*min1)*4 + ((a-1)*4*min2) + ((a-2)*(a-2)*min1 + 4*(a-2)*min2 + 4*min3);
	
	int max=0;
	
	if(a==1)
	{
		result=0;
		for(int i=0; i<6; i++)
		{
			result+=arr[i];
			if(arr[i]>max)
			{
				max=arr[i];
			}
		}
		result=result-max;
	}
	
	cout<<result;
	
	return 0;
}