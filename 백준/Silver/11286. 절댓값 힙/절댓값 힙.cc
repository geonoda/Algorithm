#include <iostream>
#include <queue>

using namespace std;

struct num{
	int id;
	num(int m)
	{
		this->id=m;
	}
	bool operator<(const num s) const {//s가 새로 추가되는 객체를 의미함
		if(s.id<0)
		{
			if(this->id>0)
			{
				if(this->id==-s.id)
				{
					return this->id > s.id;
				}
				return this->id > -s.id;
			}
			else if(this->id<0)
			{
				return -this->id > -s.id;
			}
			
			
		}
		else
		{
			if(this->id<0)
			{
				return -this->id>s.id;
			 }
			 else
			 {
			 	return this->id > s.id;
			 }
		}
		
		
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a=0;
	cin>>a;
	priority_queue<num> pq;
	
	for(int i=0; i<a; i++)
	{
		int b=0;
		cin>>b;
		if(b==0)
		{
			if(pq.empty())
			{
				cout<<0<<'\n';
			}
			else
			{
				num temp=pq.top();
				cout<<temp.id<<'\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(num(b));
		}
	}

	
	
	return 0;
}