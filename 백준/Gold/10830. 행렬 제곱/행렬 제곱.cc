#include <iostream>

using namespace std;

long long int arr[1000][1000]={0};
long long int arr2[1000][1000]={0};

long long int re(int a, long long int b);
long long int c;
int main(void)
{
	int a=0;
	long long int b=0;
	c=b;
	cin>>a>>b;
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			cin>>arr[i][j];
			arr2[i][j]=arr[i][j];
		}
	}
	if(b==1)
	{
	
	}
	
	else
	{
		re(a,b);
	}
	
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			cout<<arr2[i][j]%1000<<" ";
		}
		cout<<endl;
	}
	return 0;
}

long long int re(int a, long long int b)
{
	
	
	if(b/2>1)
	{
		//cout<<1;
		re(a,b/2);
	}

	long long int arr3[10][10]={0};
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			for(int l=0; l<a; l++)
			{
				arr3[i][j]=arr3[i][j]+arr2[i][l]*arr2[l][j];
			}
			arr3[i][j]=arr3[i][j]%1000;
		}
		
	}
	for(int i=0; i<a; i++)
		{
			for(int j=0; j<a; j++)
			{
				arr2[i][j]=arr3[i][j];
			}
		}
	long long int arr4[10][10]={0};

	if(b%2!=0)
	{
		for(int i=0; i<a; i++)
	{
		for(int j=0; j<a; j++)
		{
			for(int l=0; l<a; l++)
			{
				if(b%2!=0)
				{
					arr4[i][j]=arr4[i][j]+arr2[i][l]*arr[l][j];
				}
			}
			arr4[i][j]=arr4[i][j]%1000;
		}
		
	}
	for(int i=0; i<a; i++)
		{
			for(int j=0; j<a; j++)
			{
				arr2[i][j]=arr4[i][j];
			}
		}	
	}
	
		
	return 0;
}