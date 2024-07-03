#include <iostream>
#include <queue>

using namespace std;

int arr[51][51];

int BFS(int i, int j);

int row=0;
int col=0;

int visited[51][51];

int main(void)
{

	cin>>row>>col;
	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			char c1;
			cin>>c1;
			if(c1=='L')
			{
				arr[i][j]=1;
			}
			else
			{
				arr[i][j]=0;
			}
		}
	}
	int max=0;
	
	int maxi=0;
	int maxj=0;
	
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(arr[i][j]==1)
			{
				int temp=BFS(i,j);
				if(max<temp)
				{
					max=temp;
					maxi=i;
					maxj=j;	
				}
				for(int m=0; m<row; m++)
				{
					for(int l=0; l<col; l++)
					{
						visited[m][l]=0;
					}
				}
				
			}
			
		}
	}

	cout<<max<<endl;
	
	return 0;
}

int BFS(int i, int j)
{
	queue<pair<int,int>> Q;
	queue<int> Q2;
	int result=0;
	Q.push(make_pair(i,j));
	Q2.push(0);
	visited[i][j]=1;
	
	
	while(!Q.empty())
	{
		int num1=Q.front().first;
		int num2=Q.front().second;
		int count=Q2.front();
		result=count;
		Q.pop();
		Q2.pop();
		
		if(arr[num1+1][num2]==1 && visited[num1+1][num2]==0 && num1+1<row)
		{
			Q.push(make_pair(num1+1,num2));
			Q2.push(count+1);
			visited[num1+1][num2]=1;
		}
		if(arr[num1-1][num2]==1 && visited[num1-1][num2]==0 && num1-1>-1)
		{
			Q.push(make_pair(num1-1,num2));
			Q2.push(count+1);
			visited[num1-1][num2]=1;
		}
		if(arr[num1][num2+1]==1 && visited[num1][num2+1]==0 && num2+1<col)
		{
			Q.push(make_pair(num1,num2+1));
			Q2.push(count+1);
			visited[num1][num2+1]=1;
		}
		if(arr[num1][num2-1]==1 && visited[num1][num2-1]==0 && num2-1>-1)
		{
			Q.push(make_pair(num1,num2-1));
			Q2.push(count+1);
			visited[num1][num2-1]=1;
		}
		
	}
	
	return result;
}