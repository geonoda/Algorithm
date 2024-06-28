#include <iostream>
#define INF 987654321

using namespace std;

int arr[101][101];

int main(void)
{
	int a=0;
	
	cin>>a;
	
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=a; j++)
		{		
			cin>>arr[i][j];
			if(arr[i][j]==0)
			{
				arr[i][j]=INF;
			}
		}
	}
	
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=a; j++)
		{
			for(int k=1; k<=a; k++)
			{
				if(arr[j][i]+arr[i][k]<arr[j][k])
				{
					arr[j][k]=arr[j][i]+arr[i][k];
				}
			}
		}
	}
	
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=a; j++)
		{
			if(arr[i][j]==INF)
			{
				cout<<0<<" ";
			}
			else
			{
				cout<<1<<" ";
			}
			
		}
		cout<<endl;
	}
	
	return 0;
}