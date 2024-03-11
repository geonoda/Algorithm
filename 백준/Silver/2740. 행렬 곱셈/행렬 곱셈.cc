#include <iostream>

using namespace std;

int arr[1000][1000]={0};
int arr2[1000][1000]={0};
int arr3[1000][1000]={0};
int main(void)
{
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	cin>>a>>b;	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	cin>>c>>d;
	for(int i=0; i<c; i++)
	{
		for(int j=0; j<d; j++)
		{
			cin>>arr2[i][j];
		}
	}
	
	
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<d; j++)
		{
			for(int l=0; l<b; l++)
			{
				arr3[i][j]=arr3[i][j]+arr[i][l]*arr2[l][j];
			}
			cout<<arr3[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}