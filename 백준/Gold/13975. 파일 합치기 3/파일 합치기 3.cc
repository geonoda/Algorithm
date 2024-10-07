#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int T=0;
	cin>>T; 
	for(int i=0; i<T; i++)
	{
		long long sum=0;
		int N=0;
		cin>>N;
		priority_queue<long long> pq;
		for(int i=0; i<N; i++)
		{
			long long num=0;
			cin>>num;
			pq.push(-num);
		}
		
		while(!pq.empty())
		{
			long long num1=-pq.top();
			pq.pop();
			
			long long num2=-pq.top();
			pq.pop();
			//cout<<num1+num2<<endl;
			sum=sum+num1+num2;
			if(pq.empty())
			{
				cout<<sum<<endl;
				break;
			}
			pq.push(-(num1+num2));
		}
	}
	return 0;
}