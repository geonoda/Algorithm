#include <iostream>

using namespace std;
int arr[1000001]={0};
int main(void)
{
	int a=0;
	cin>>a;
	long long int sum=0;
	int count=0;
	for(int i=0; i<a; i++)
	{
		int num=0;
		cin>>num;
		if(num==0)
		{
			count--;
			sum=sum-arr[count];
		}
		else
		{
			arr[count]=num;
			sum=sum+num;
			count++;
		}
	}
	cout<<sum;
	return 0;
}