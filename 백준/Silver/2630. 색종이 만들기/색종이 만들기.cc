#include <iostream>

using namespace std;

int arr[1000][1000];

int re(int x, int y,int n);
int recount=0;
int recount2=0;
int main(void)
{
	int a;
	cin>>a;
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			cin>>arr[i][j];
		}
	}
	re(0,0,a);
	cout<<recount<<endl;
	cout<<recount2;
	return 0;
}

int re(int x, int y,int n)
{
	int count=0;
	for(int i=x; i<x+n; i++)
	{
		for(int j=y; j<y+n; j++)
		{
			if(arr[i][j]==1)
			{
				count++;
			}
		}
	}
	if(count==n*n||count==0)
	{
		if(count==0)
		{
			recount++;	
		}
		else
		{
			recount2++;
		}
		
		return 0;
	}
	else
	{
		re(n/2+x,0+y,n/2);
		re(0+x,n/2+y,n/2);
		re(x,y,n/2);
		re(n/2+x,n/2+y,n/2);
	}
	return 0;
}