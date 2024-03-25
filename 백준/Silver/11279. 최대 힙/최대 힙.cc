#include <iostream>
#include <algorithm>
#include <queue>
#include <functional> 
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<int> pq;
	int a=0;
	cin>>a;
	
	for(int i=0; i<a; i++)
	{
		int num=0;
		cin>>num;
		if(num==0)
		{
			if(pq.empty())
			{
				cout<<0<<'\n';
			}
			
			else
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
			
		}
		else
		{
			pq.push(num);
		}
	}
	
	return 0;
}
