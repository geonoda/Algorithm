#include <iostream>

using namespace std;

int arr[3000][3000];

int re(int x, int y, int n);

int num1;
int num2;
int num3;

int main(void)
{
	int a=0;
	cin>>a;

	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	re(0,0,a);
	
	cout<<num3<<endl;
	cout<<num1<<endl;
	cout<<num2<<endl;

	return 0;
}

int re(int x, int y, int n)
{
	int count1=0;
	int count2=0;
	int count3=0;
	for(int i=x+0; i<x+n; i++)
	{
		for(int j=y+0; j<y+n; j++)
		{
			if(arr[i][j]==0)
			{
				count1++;
			}
			else if(arr[i][j]==1)
			{
				count2++;
			}
			else if(arr[i][j]==-1)
			{
				count3++;
			}
		}
	}
	if(count1==n*n||count2==n*n||count3==n*n)
	{
		if(count1==n*n)
		{
			num1++;
		}
		else if(count2==n*n)
		{
			num2++;
		}
		else if(count3==n*n)
		{
			num3++;
		}
		return 0;
	}
	else
	{
		re(x,y,n/3);
		re(x,y+n/3,n/3);
		re(x,y+2*n/3,n/3);
		
		re(x+n/3,y,n/3);
		re(x+n/3,y+n/3,n/3);
		re(x+n/3,y+2*n/3,n/3);
		
		re(x+2*n/3,y,n/3);
		re(x+2*n/3,y+n/3,n/3);
		re(x+2*n/3,y+2*n/3,n/3);	
	}
	return 0;
}