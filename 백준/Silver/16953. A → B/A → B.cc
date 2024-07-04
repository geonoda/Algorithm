#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int num1=0;
	int num2=0;
	
	cin>>num1>>num2;
	
	int count=1;
	
	while(true)
	{
		if(num2%2==0)
		{
			num2=num2/2;
			count++;
		}
		else if(num2%10==1)
		{
			num2=num2/10;
			count++;
		}
		else
		{
			cout<<-1;
			break;
		}
		
		if(num2==num1)
		{
			cout<<count;
			break;
		}
		else if(num2<num1)
		{
			cout<<-1;
			break;
		}
	}
	
	return 0;
}