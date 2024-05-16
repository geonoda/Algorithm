#include <iostream>

#define INF 987654321

using namespace std;

int city[500][500];

int sol(int a);

int main(void)
{
	int a=0;
	int b=0;
	cin>>a>>b;
	
	for(int i=0; i<b; i++)
	{
		int S=0;
		int E=0;
		int D=0;
		cin>>S>>E>>D;
		city[S][E]=D;
	}
	
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=a; j++)
		{
			if(city[i][j]==0)
			{
				city[i][j]=INF;
			}
			if(i==j)
			{
				city[i][j]=0;
			}
		}
	}
	
	int result=sol(a);
	cout<<result;
	
	return 0;
}

int sol(int a)
{
	for(int k=1; k<=a; k++)
	{
		for(int i=1; i<=a; i++)
		{
			for(int j=1; j<=a; j++)
			{
				if(city[i][k]+city[k][j]<city[i][j])
				{
					city[i][j]=city[i][k]+city[k][j];
				}
			}
		}
	}
	
	int min=INF;
	
	for(int i=1; i<=a; i++)
	{
		for(int j=i+1; j<=a; j++)
		{
			if(min>city[i][j]+city[j][i])
			{
				min=city[i][j]+city[j][i];
			}
		}
	}
	
	if(min==INF)
	{
		min=-1;
	}
	
	return min;
}


