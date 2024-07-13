#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
queue <pair<int,int> > Q;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};

int BFS();

int a=0;
int b=0;

int main(void)
{
	
	cin>>a>>b;
	
	int sum=0;
	int count=0;
	int page=0;
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			cin>>arr[i][j];
			if(arr[i][j]==1)
			{
				sum++;
			}
		}
	}
	
	while(true)
	{
		int temp=BFS();
		count+=temp;
		page++;
		
		
		if(count==sum)
		{
			cout<<page<<endl;
			cout<<temp;
			break;
		}
	}
	
	return 0;
}

int BFS()
{
	int visited[101][101]={0};
	
	int count=0;
	
	Q.push(make_pair(0,0));
	
	while(!Q.empty())
	{
		int num1=Q.front().first;
		int num2=Q.front().second;
		
		Q.pop();
		for(int i=0; i<4; i++)
		{
			if(visited[num1+row[i]][num2+col[i]]==0&&num1+row[i]>-1&&num1+row[i]<a&&num2+col[i]>-1&&num2+col[i]<b)
			{
				visited[num1+row[i]][num2+col[i]]=1;

				if(arr[num1+row[i]][num2+col[i]]==0)
				{
					Q.push(make_pair(num1+row[i],num2+col[i]));
				}
				else
				{
					count++;
					arr[num1+row[i]][num2+col[i]]=0;
				}
				
			}
		}
	}
	
	return count;
}