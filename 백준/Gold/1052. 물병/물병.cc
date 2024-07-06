#include <iostream>

using namespace std;

int arr[1001];

int main(void)
{
	int a=0;
	int size=0;
	
	cin>>a>>size;
	
	for(int i=0; i<size; i++)
	{
		arr[i]=1;
	}
	a=a-size;
	
	if(a<size)
	{
		cout<<0;
		return 0;
	}
	
	int circle=0;
	
	while(true)
	{
		if(a==0)
		{
			break;
		}
		if(a-arr[circle]>=0)
		{
			a=a-arr[circle];
			arr[circle]=arr[circle]*2;
		}
		else
		{
			if(circle==size-1)
			{
				a=(-(a-arr[circle]));
				break;
			}
			circle=(circle+1)%size;
		}
		
	}
	
	
	cout<<a;
	
	return 0;
}