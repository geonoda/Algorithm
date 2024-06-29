#include <iostream>
#include <algorithm>

using namespace std;

int arr[51];
int arr2[51];
int main(void)
{
	int a=0;
	cin>>a;
	
	int count1=0;
	int count2=0;
	
	for(int i=0; i<a; i++)
	{
		int num=0;
		cin>>num;
		if(num>0)
		{
			arr[count1]=-num;
			count1++;
		}
		else
		{
			arr2[count2]=num;
			count2++;
		}
	}
	
	sort(arr,arr+count1);
	sort(arr2,arr2+count2);
	
	int sum=0;
	
	
	for(int i=0; i<count1; i=i+2)
	{
		int num1=-arr[i];
		int num2=-arr[i+1];
		
		if((num1==1||num2==1))
		{
			sum=sum+num1+num2;
		}
		else
		{
			if(count1==1||i==count1-1)
			{
				sum=sum+num1;
			}
			else
			{
				sum=sum+num1*num2;
			}
		}
	}
	
	for(int i=0; i<count2; i=i+2)
	{
		int num1=arr2[i];
		int num2=arr2[i+1];
		
		if(i==count2-1)
		{
			sum=sum+num1;
		}
		else
		{
			sum=sum+num1*num2;
		}
		
	}
	
	cout<<sum;
		
	return 0;
}