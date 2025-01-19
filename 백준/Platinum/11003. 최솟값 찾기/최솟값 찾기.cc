#include <iostream>
#include <queue>
using namespace std;

void Assignment1();
//int A[5000000]; 입력받는 배열조차 필요없다. 우선순위 큐만 있으면 된다. 
priority_queue<pair<int,int> > Q;

int main(void)
{
	ios::sync_with_stdio(false);//cin과 cout 시간초과 방지코드 
    cin.tie(NULL);
	Assignment1();
	return 0;
}

void Assignment1()
{
	int N=0;
	int L=0;
	cin>>N>>L;

	for(int i=1; i<=N; i++)
	{
		int num=0;
		cin>>num;
		Q.push(make_pair(-num,i));
		while(i-Q.top().second>=L)
		{
			Q.pop();
		}
		cout<<-Q.top().first<<" ";
	}
	
}