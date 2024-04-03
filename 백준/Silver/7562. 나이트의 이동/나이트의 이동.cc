#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int visited[500][500];
queue<int> Q;
int arrsi=0;
int result[1000000];
int Rcount=0;

void BFS(int sx,int sy,int ex, int ey);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a=0;
	cin>>a;
	for(int i=0; i<a; i++)
	{
		
		cin>>arrsi;
		
		int ssx=0;
		int ssy=0;
		int eex=0;
		int eey=0;
		cin>>ssx>>ssy>>eex>>eey;
		for(int l=0; l<arrsi; l++)
		{
			for(int j=0; j<arrsi; j++)
			{
				visited[l][j]=0;
			}
		}
		BFS(ssx,ssy,eex,eey);
		while(!Q.empty())
		{
			Q.pop();
		}		
		
	}
	for(int i=0; i<Rcount; i++)
	{
		cout<<result[i]<<'\n';
	}
	return 0;
}
void BFS(int sx,int sy,int ex, int ey)
{	
	int count=0;
	visited[sx][sy]=1;
	Q.push(sx);
	Q.push(sy);
	Q.push(count);
	while(!Q.empty())
	{
		int tx=Q.front();
		Q.pop();
		int ty=Q.front();
		Q.pop();
		int tcount=Q.front();
		Q.pop();
		visited[tx][ty]=1;
		
		if(tx==ex&&ty==ey)
		{
			result[Rcount]=tcount;
			Rcount++;
			break;
		}
		tcount++;
		if(visited[tx+2][ty+1]==0&&tx+2>=0&&ty+1>=0&&tx+2<arrsi&&ty+1<arrsi)
		{
			Q.push(tx+2);
			Q.push(ty+1);
			Q.push(tcount);
			visited[tx+2][ty+1]=1;
		}
		if(visited[tx+2][ty-1]==0&&tx+2>=0&&ty-1>=0&&tx+2<arrsi&&ty-1<arrsi)
		{
			Q.push(tx+2);
			Q.push(ty-1);
			Q.push(tcount);
			visited[tx+2][ty-1]=1;
		}
		if(visited[tx-2][ty+1]==0&&tx-2>=0&&ty+1>=0&&tx-2<arrsi&&ty+1<arrsi)
		{
			Q.push(tx-2);
			Q.push(ty+1);
			Q.push(tcount);
			visited[tx-2][ty+1]=1;
		}
		if(visited[tx-2][ty-1]==0&&tx-2>=0&&ty-1>=0&&tx-2<arrsi&&ty-1<arrsi)
		{
			Q.push(tx-2);
			Q.push(ty-1);
			Q.push(tcount);
			visited[tx-2][ty-1]=1;
		}
		
		if(visited[tx+1][ty+2]==0&&tx+1>=0&&ty+2>=0&&tx+1<arrsi&&ty+2<arrsi)
		{
			Q.push(tx+1);
			Q.push(ty+2);
			Q.push(tcount);
			visited[tx+1][ty+2]=1;
		}
		if(visited[tx+1][ty-2]==0&&tx+1>=0&&ty-2>=0&&tx+1<arrsi&&ty-2<arrsi)
		{
			Q.push(tx+1);
			Q.push(ty-2);
			Q.push(tcount);
			visited[tx+1][ty-2]=1;
		}
		if(visited[tx-1][ty+2]==0&&tx-1>=0&&ty+2>=0&&tx-1<arrsi&&ty+2<arrsi)
		{
			Q.push(tx-1);
			Q.push(ty+2);
			Q.push(tcount);
			visited[tx-1][ty+2]=1;
		}
		if(visited[tx-1][ty-2]==0&&tx-1>=0&&ty+2>=0&&tx-1<arrsi&&ty-2<arrsi)
		{
			Q.push(tx-1);
			Q.push(ty-2);
			Q.push(tcount);
			visited[tx-1][ty-2]=1;
		}	
	}	
}