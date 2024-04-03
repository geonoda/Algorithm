#include <iostream>
#include <queue>

using namespace std;

int visited[100001];

queue<int> Q;

int BFS(int start, int end,int count);

int count1=0;

int main(void)
{
	int a=0;
	int b=0;
	cin>>a>>b;
	BFS(a,b,0);
	return 0;
}

int BFS(int start, int end,int count)
{
	visited[start]=1;
	Q.push(start);
	Q.push(count);
	while(!Q.empty())
	{
		int temp=Q.front();
		Q.pop();
		int tempT=Q.front();
		Q.pop();
		tempT++;
		visited[temp]=1;
		if(temp!=end)
		{
			if(visited[temp+1]==0&&temp+1<=100000&&temp+1>=0)
			{
				Q.push(temp+1);
				Q.push(tempT);
			}
			
			
			if(visited[temp-1]==0&&temp-1<=100000&&temp-1>=0)
			{
				Q.push(temp-1);
				Q.push(tempT);
			}
			
			
			if(visited[temp*2]==0&&temp*2<=100000&&temp*2>=0)
			{
				Q.push(temp*2);
				Q.push(tempT);
			}
		}
		else
		{
			cout<<tempT-1;
			break;
		}
	}
	return 0;
}