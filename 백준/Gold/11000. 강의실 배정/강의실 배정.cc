#include <iostream>
#include <queue>

using namespace std;
priority_queue<pair<int, int> > Q;

priority_queue<int> Q2;
int arr[200001];

int main(void)
{
	int a=0;
	cin>>a;
	
	for(int i=0; i<a; i++)
	{
		int num1=0;
		int num2=0;
		cin>>num1>>num2;
		Q.push(make_pair(-num1,num2));
	}
	
	int count=1;
	int min=0;
	Q2.push(0);
	while(!Q.empty())
	{
		int num1=-Q.top().first;
		int num2=Q.top().second;
		Q.pop();
		
		if(num1<-Q2.top())
		{
			Q2.push(-num2);
			count++;
		}
		else
		{
			Q2.pop();
			Q2.push(-num2);
		}
		
	}
	
	cout<<count;
	
	return 0;
}