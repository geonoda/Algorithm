#include <iostream>

using namespace std;

void DFS(int a, int b, int row, int col);

int arr[51][51];
int visited[51][51];

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	while(true)
	{
		int num1=0;
		int num2=0;
		
		cin>>num1>>num2;
		
		if(num1==0&&num2==0)
		{
			break;
		}
		
		for(int i=0; i<num2; i++)
		{
			for(int j=0; j<num1; j++)
			{
				cin>>arr[i][j];
			}
		}
		
		int count=0;
		
		for(int i=0; i<num2; i++)
		{
			for(int j=0; j<num1; j++)
			{
				if(arr[i][j]==1&&visited[i][j]==0)
				{
					DFS(i, j, num2, num1);
					count++;
				}
			}
		}
		cout<<count<<endl;
		
		for(int i=0; i<num2; i++)
		{
			for(int j=0; j<num1; j++)
			{
				arr[i][j]=0;
				visited[i][j]=0;
			}
		}
	}
	return 0;
}

void DFS(int a, int b, int row, int col)
{
	for(int i=-1; i<2; i++)
	{
		for(int j=-1; j<2; j++)
		{
			if(arr[a+i][b+j]==1&&visited[a+i][b+j]==0&&a+i>-1&&a+i<row&& b+j>-1&& b+j<col)
			{
				visited[a+i][b+j]=1;
				DFS(a+i,b+j,row,col);
			}
		}
	}
}