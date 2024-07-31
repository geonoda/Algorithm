#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long int> Q;
priority_queue<long long int> Q2;
int main(void)
{
	int N=0;
	int M=0;
	
	cin>>N>>M;
	
	for(int i=0; i<N; i++)
	{
		long long int num=0;
		cin>>num;
		Q.push(num);
	}
	
	if(M>N)
	{
		M=N;
	}
	
	for(int i=0; i<M; i++)
	{
		long long int temp=Q.top();
		Q.pop();
		Q2.push(-temp);
	}

	while(!Q.empty())
	{
		long long int num=Q.top();
		Q.pop();
		long long int num2=-Q2.top();
		Q2.pop();
		Q2.push(-(num+num2));
	}
	
	long long int min=0;
	while(!Q2.empty())
	{
		long long int num=-Q2.top();
		Q2.pop();
		if(num>min)
		{
			min=num;
		}
	}
	
	cout<<min;
	
	return 0;
}