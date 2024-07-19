#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[51][51];
int arr2[51][51];
vector <pair<int,int> > V;

int row[4]={0,0,-1,1};
int col[4]={-1,1,0,0};
int min1=987654321;

void DFS(int count, int start);

int N=0;
int M=0;

int vi=0;

int main(void)
{
	cin>>N>>M;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin>>arr[i][j];	
			if(arr[i][j]==2)
			{
				V.push_back(make_pair(i,j));
				vi++;
			}
			else
			{
				arr2[i][j]=arr[i][j];
			}
		}
	}
	
	DFS(0,0);
	
	if(min1==987654321)
	{
		cout<<-1;
	}
	else
	{
		cout<<min1;
	}
	
	return 0;
}

int result[11];

void DFS(int count, int start)
{
	if(count==M)
	{
		queue<pair<int,int> > Q;
		queue<int> Q2;
		
		int temp[51][51]={0};
		int arrvisited[51][51]={0};
		
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				temp[i][j]=arr2[i][j];
			}
		}
		for(int i=0; i<M; i++)//바이러스 위치를 결정함.(조합)
		{
			int num1=V[result[i]].first;
			int num2=V[result[i]].second;
			temp[num1][num2]=2;
			arrvisited[num1][num2]=1;
			Q.push(make_pair(num1,num2));
			Q2.push(0);
		}
		
		int time=0;
		while(!Q.empty())
		{
			int num1=Q.front().first;
			int num2=Q.front().second;
			time=Q2.front();
			Q.pop();
			Q2.pop();
			
			for(int i=0; i<4; i++)
			{
				if(temp[num1+row[i]][num2+col[i]]==0&&arrvisited[num1+row[i]][num2+col[i]]==0&&num1+row[i]>-1&&num1+row[i]<N&&num2+col[i]>-1&&num2+col[i]<N)
				{
					Q.push(make_pair(num1+row[i],num2+col[i]));
					Q2.push(time+1);
					arrvisited[num1+row[i]][num2+col[i]]=1;
				}
			}
		}
		int sig=0;
		for(int i=0; i<N; i++)//방문되지 않은 곳을 확인하는 작업 
		{
			for(int j=0; j<N; j++)
			{
				if(temp[i][j]==0)
				{
					if(arrvisited[i][j]!=1)
					{
						sig=1;
					}
				}
			}
		}
		if(sig==0&&time<min1)//전부 방문했다면?? 
		{
			min1=time;
		}
	}
	else//조합을 만든다. 
	{
		for(int i=start; i<vi; i++)//strat를 통해 작은 값을 탐색하지 않음으로 중복되는 조합을 피함. 
		{	
			result[count]=i;
			DFS(count+1,i+1);
			result[count]=0;
		}
	}
}