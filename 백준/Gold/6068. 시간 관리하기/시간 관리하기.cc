#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int,int> > Q;

int main(void)
{
	int N=0;
	cin>>N;
	
	for(int i=0; i<N; i++)
	{
		int num1=0;
		int num2=0;
		
		cin>>num1>>num2;
		Q.push(make_pair(-num2,num1));
	} 
	
	long long int sum=0;
	long long int min=987654321;
	
	while(!Q.empty())
	{
		sum+=Q.top().second;
		long long int time=-Q.top().first;
		Q.pop();
	
		
		if(min>time-sum)
		{
			min=time-sum;
		}
	}
	if(min<0)
	{
		cout<<-1;
	}
	else
	{
		cout<<min;
	}
	
	
	
	return 0;
} 