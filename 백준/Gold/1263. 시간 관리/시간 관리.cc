#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
priority_queue <pair<int,int> > Q;

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
	
	int sum=0;
	int min=987654321;

	while(!Q.empty())
	{
		int endtime=-Q.top().first;
		sum=sum+Q.top().second;
		Q.pop();
		if(min>endtime-sum)
		{
			min=endtime-sum;
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