#include <iostream>
#include <queue>

using namespace std;

priority_queue <int> Q;


int main(void)
{
	int a=0;
	cin>>a;
	
	for(int i=0; i<a; i++)
	{
		int num=0;
		cin>>num;
		Q.push(-num);
	}
	
	int sum=0;
	
	while(Q.size()>1)
	{
		int num1=Q.top();
		Q.pop();
		int num2=Q.top();
		Q.pop();
		Q.push((num1+num2));
		sum=sum-(num1+num2);
	}
	
	cout<<sum;
	return 0;
}