#include <iostream>

using namespace std;

int DFS(int x, int y);

int arr[51][51]={0};


int count1=0;


int visited[51][51]={0};
int CR=0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=0; i<51; i++)
	{
		for(int j=0; j<51; j++)
		{
			arr[i][j]=0;
			visited[i][j]=0;
		}
	}
	int a=0;
	cin>>a;
	for(int i=0; i<a; i++)
	{
		int num1=0;
		int num2=0;
		int num3=0;
		
		cin>>num1>>num2>>num3;
		
		
		for(int j=0; j<num3; j++)
		{
			int m=0;
			int n=0;
			cin>>m>>n;
			arr[m][n]=1;
			
		}
		for(int x=0; x<num1; x++)
		{
			for(int y=0; y<num2; y++)
			{
				count1=0;
				int result=DFS(x,y);
				if(result!=0)
				{
					CR++;
				}
			}
		}
		cout<<CR<<'\n';
		for(int x=0; x<num1; x++)
		{
			for(int y=0; y<num2; y++)
			{
				arr[x][y]=0;
				visited[x][y]=0;
			}
		}
		CR=0;
	}
	return 0;
}

int DFS(int x, int y)
{
	if(visited[x][y]==1)
	{
		return 0;
	}
	
	visited[x][y]=1;
	
	if(arr[x][y]==1)
	{
		count1++;
		if(arr[x+1][y]==1)
		{
			DFS(x+1,y);
		}
		if(arr[x-1][y]==1)
		{
			DFS(x-1,y);
		}
		if(arr[x][y+1]==1)
		{
			DFS(x,y+1);
		}
		if(arr[x][y-1]==1)
		{
			DFS(x,y-1);
		}
	}
	
	return count1;
}