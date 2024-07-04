#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int test=0;
	cin>>test;
	
	for(int i=0; i<test; i++)
	{
		int a=0;
		cin>>a;
		vector<pair<int,int> > V;
		for(int i=0; i<a; i++)
		{
			int num1=0;
			int num2=0;
			cin>>num1>>num2;
			
			V.push_back(make_pair(num1,num2));
		}
		sort(V.begin(), V.end());
		
		int count=1;
		int min=V[0].second;
		for(int i=1; i<V.size(); i++)
		{
			if(V[i].second<=min)
			{
				count++;
				min=V[i].second;
			}
		}
		cout<<count<<endl;
	}
	
	
	return 0;
}