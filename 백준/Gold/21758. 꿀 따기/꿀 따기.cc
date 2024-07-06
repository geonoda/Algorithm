#include <iostream>

using namespace std;

int arr[100001];

int main(void)
{
	int N=0;
	cin>>N;
	
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
	}
	
	for(int i=1; i<N; i++)
	{
		arr[i]=arr[i]+arr[i-1];
	}
	
	
	//right
	int result=(arr[N-1]-arr[0]) + (arr[N-1]-arr[1]) - (arr[1]-arr[0]);
	int i=2;
	while(true)
	{
		int temp=(arr[N-1]-arr[0]) + (arr[N-1]-arr[i]) - (arr[i]-arr[i-1]);
		if(result<temp)
		{
			result=temp;
		}
		
		i++;
		
		if(i>N-2)
		{
			break;
		}
	}
	
	//left
	int result2=(arr[N-2]) + (arr[N-3]) - (arr[N-2]-arr[N-3]);
	int j=4;
	while(true)
	{
		int temp=(arr[N-2]) + (arr[N-j]) - (arr[N-j+1]-arr[N-j]);
		if(result2<temp)
		{
			result2=temp;
		}
		
		j++;
		
		if(j>=N)
		{
			break;
		}
	}
	
	//middle
	
	int result3=(arr[1]-arr[0]) + (arr[N-2]-arr[0]);
	int l=2;
	while(true)
	{
		int temp=(arr[l]-arr[0]) + (arr[N-2]-arr[l-1]);
		if(result3<temp)
		{
			result3=temp;
		}
		
		l++;
		
		if(l>N-2)
		{
			break;
		}
	}
	
	int max=0;
	
	if(max<result)
	{
		max=result;
	}
	if(max<result2)
	{
		max=result2;
	}
	if(max<result3)
	{
		max=result3;
	}
	cout<<max;

	
	return 0;
}
