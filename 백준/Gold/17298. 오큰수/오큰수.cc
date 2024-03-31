#include <iostream>
#include <stack>
using namespace std;
int arr[1000001];
int NGE[1000001];
int main(void)
{
	stack<int> s;
	int a=0;
	cin>>a;
	for(int i=0; i<a; i++)
	{
		cin>>arr[i];
	}
	
	for(int i=a-1; i>=0; i--)
	{
		while(!s.empty()&&s.top()<=arr[i])//만약 arr[i]가 6이고 스택의 모습이 5, 8이면?? 5를 팝해야겠지? 
		{
			s.pop();
		}
		if(s.empty())
		{
			NGE[i]=-1;
		}
		else
		{
			NGE[i]=s.top();
		}
		s.push(arr[i]);
	}
	for(int i=0; i<a; i++)
	{
		cout<<NGE[i]<<" ";
	}
	return 0;
}