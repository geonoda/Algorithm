#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int> > Q;

int arr[10][10];

void BFS(int arr[10][10]);
void DFS(int row, int col,int arr[10][10],int count);
int max1=0;
int a=0;
int b=0;
int main(void)
{
	cin>>a>>b;
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	DFS(0,0,arr,0);
	
	
	cout<<max1;
	
	return 0;
}

void DFS(int row, int col, int arr[10][10],int count)
{
	int temp[10][10];
	for(int i=row; i<a; i++)
	{
		int n=0;
		if(i==row)
		{
			n=col;
		}
		for(int j=n; j<b; j++)
		{
			for(int m=0; m<10; m++)
			{
				for(int k=0; k<10; k++)
				{
					temp[m][k]=arr[m][k];
				}
			}
			if(temp[i][j]==0)
			{
				if(count<2)
				{
					temp[i][j]=1;
					DFS(i,j,temp,count+1);
				}
				else
				{
					temp[i][j]=1;
					BFS(temp);
				}	
			}
		}
	}
}

void BFS(int arr[10][10])
{
	int temp[10][10];
	for(int m=0; m<10; m++)
	{
		for(int k=0; k<10; k++)
		{
			temp[m][k]=arr[m][k];
		}
	}
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			if(temp[i][j]==2)
			{
				Q.push(make_pair(i,j));
			}
		}
	}
	
	while(!Q.empty())
	{
		int i=Q.front().first;
		int j=Q.front().second;
		Q.pop();
		
		if(temp[i][j+1]==0&&j+1>-1&&j+1<b)
		{
			temp[i][j+1]=2;
			Q.push(make_pair(i,j+1));
		}
		if(temp[i][j-1]==0&&j-1>-1&&j-1<b)
		{
			temp[i][j-1]=2;
			Q.push(make_pair(i,j-1));
		}
		if(temp[i+1][j]==0&&i+1>-1&&i+1<a)
		{
			temp[i+1][j]=2;
			Q.push(make_pair(i+1,j));
		}
		if(temp[i-1][j]==0&&i-1>-1&&i-1<a)
		{
			temp[i-1][j]=2;
			Q.push(make_pair(i-1,j));
		}
	}
	
	int count=0;
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			if(temp[i][j]==0)
			{
				count++;
			}
		}
	}
	
	if(count>max1)
	{
		max1=count;
	}
}