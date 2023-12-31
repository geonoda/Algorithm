#include <iostream>

using namespace std;

int main(void)
{
	int a;
	int b;
	int c;
	int num;
	int count=0;
	cin>>a>>b>>num;
	
	num=num-a;
	count++;
	count=count+num/(a-b);
	if(num%(a-b)>0)
	{
		count++;
	}
	cout<<count;
	return 0;
}