#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int > > Q;

int main(void)
{
	int count=0;
	cin>>count;
	
	for(int i=0; i<count; i++)
	{
		int a=0;
		int b=0;
		cin>>a>>b;
		Q.push_back(make_pair(b,a));
	}
		
	sort(Q.begin(), Q.end());
	
	int start=Q[0].first;
	int k=1;
	
	for(int i=1; i<count; i++)
	{
		if(Q[i].second>=start)
		{
			k++;
			start=Q[i].first;
		}
	}
	cout<<k;
	
	
	return 0;
	
}