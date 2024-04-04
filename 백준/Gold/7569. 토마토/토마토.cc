#include <iostream>
#include <queue>

using namespace std;

int arr[100][100][100];
int visited[100][100][100];
queue<int> Q;
void BFS();

int a=0;
int b=0;
int c=0;

int Pcount=0;
int Mcount=0;
int Zcount=0;

int main(void)
{
	
	cin>>a>>b>>c;
	for(int l=0; l<c; l++)
	{
		for(int i=0; i<b; i++)
		{
			for(int j=0; j<a; j++)
			{
				cin>>arr[l][i][j];
				if(arr[l][i][j]==1)
				{
					Pcount++;
					Q.push(l);
					Q.push(i);
					Q.push(j);
					Q.push(0);
				}
				else if(arr[l][i][j]==0)
				{
					Zcount++;
				}
				else if(arr[l][i][j]==-1)
				{
					Mcount++;
				}
			}
		}
	}
	
	if(a*b*c==Pcount+Mcount)
	{
		cout<<0;
	}
	else
	{
		BFS();
	}
	
	return 0;
}

void BFS()
{
	int sum=0;
	while(!Q.empty())
	{
		int h=Q.front();
		Q.pop();
		int x=Q.front();
		Q.pop();
		int y=Q.front();
		Q.pop();
		int date=Q.front();
		Q.pop();
		sum++;//익었나?? 확인하는 것
		visited[h][x][y]=1;
		arr[h][x][y]=1;
		if(Zcount+Pcount==sum)
		{
			cout<<date<<endl;
			return;
		}
		date++;
		
		for(int i=-1; i<2; i=i+2)
		{
			if(x+i>=0&&x+i<b&&visited[h][x+i][y]==0&&arr[h][x+i][y]==0)
			{
				visited[h][x+i][y]=1;
				arr[h][x+i][y]=1;
				Q.push(h);
				Q.push(x+i);
				Q.push(y);
				Q.push(date);
			}
		}
		for(int j=-1; j<2; j=j+2)
		{
			if(y+j>=0&&y+j<a&&visited[h][x][y+j]==0&&arr[h][x][y+j]==0)
			{
				visited[h][x][y+j]=1;
				arr[h][x][y+j]=1;
				Q.push(h);
				Q.push(x);
				Q.push(y+j);
				Q.push(date);
			}
		}		
		if(h+1>=0&&h+1<c&&visited[h+1][x][y]==0&&arr[h+1][x][y]==0)
		{
			visited[h+1][x][y]=1;
			arr[h+1][x][y]=1;
			Q.push(h+1);
			Q.push(x);
			Q.push(y);
			Q.push(date);
		}
		if(h-1>=0&&h-1<c&&visited[h-1][x][y]==0&&arr[h-1][x][y]==0)
		{
			visited[h-1][x][y]=1;
			arr[h-1][x][y]=1;
			Q.push(h-1);
			Q.push(x);
			Q.push(y);
			Q.push(date);
		}
	}
	cout<<-1<<endl;
	
}
