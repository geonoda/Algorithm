#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][100];

void sol(int Lnum1, int Lnum2 ,int Rnum1, int Rnum2);
int DFS(int i, int j);
int result[10000];

int row=0;
int col=0;

int main(void)
{
	int a=0;
	
	cin>>row>>col>>a;
	
	for(int i=0; i<a; i++)
	{
		int Lnum1=0;
		int Lnum2=0;
		
		cin>>Lnum1>>Lnum2;
		
		int Rnum1=0;
		int Rnum2=0;
		
		cin>>Rnum1>>Rnum2;
		
		sol(Lnum1, Lnum2 ,Rnum1, Rnum2);
	}
	
	int count=0;
	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(arr[i][j]==0)
			{
				arr[i][j]=1;
				result[count]=DFS(i,j)+1;
				count++;
			
			}
		}
	}
	
	
	
	sort(result,result+count);
	
	cout<<count<<endl;
	for(int i=0; i<count; i++)
	{
		cout<<result[i]<<" ";
	}
	
	return 0;
}

void sol(int Lnum1, int Lnum2 ,int Rnum1, int Rnum2)
{
	for(int i=Lnum2; i<Rnum2; i++)
	{
		for(int j=Lnum1; j<Rnum1; j++)
		{
			if(arr[i][j]==0)
			{
				arr[i][j]=1;
			}
		}
	}
}

int DFS(int i, int j)
{
	int result=0;
	if(arr[i+1][j]==0&&i+1<row)
	{
		arr[i+1][j]=1;
		result++;
		result+=DFS(i+1,j);
	}
	if(arr[i-1][j]==0&&i-1>-1)
	{
		arr[i-1][j]=1;
		result++;
		result+=DFS(i-1,j);
	}
	if(arr[i][j+1]==0&&j+1<col)
	{
		arr[i][j+1]=1;
		result++;
		result+=DFS(i,j+1);
	}
	if(arr[i][j-1]==0&&j-1>-1)
	{
		arr[i][j-1]=1;
		result++;
		result+=DFS(i,j-1);
	}
	return result;
}