#include <iostream>
#include <queue>

using namespace std;

queue<int> Q;

int S[101];
int B[101];
int visited[103];

void BFS();

int main(void)
{
	int a=0;
	int b=0;
	
	cin>>a>>b;
	
	for(int i=0; i<a; i++)
	{
		int num1=0;
		int num2=0;
		cin>>num1>>num2;
		S[num1]=num2;
	}
	for(int i=0; i<b; i++)
	{
		int num1=0;
		int num2=0;
		cin>>num1>>num2;
		B[num1]=num2;
	}
	
	BFS();
	
	return 0;
}

void BFS()
{
	for(int i=1; i<=6; i++)
	{
		visited[1+i]=1;
		if(S[1+i]!=0)
		{
			Q.push(S[1+i]);
		}
		else if(B[1+i]!=0)
		{
			Q.push(B[1+i]);
		}
		else
		{
			Q.push(i+1);
		}
		Q.push(1);
	}
	int b=0;
	while(!Q.empty())
	{
		int start=Q.front();
		Q.pop();
		int count=Q.front();
		Q.pop();
		visited[start]=1;
		b=count;
		if(start==100)
		{
			cout<<count;
			return;
		}

		for(int i=1; i<=6; i++)
		{
			if(visited[start+i]==0)
			{
				visited[i+start]=1;
				if(S[start+i]!=0)
				{
					Q.push(S[start+i]);
				}
				else if(B[start+i]!=0)
				{
					Q.push(B[start+i]);
				}
				else
				{
					Q.push(i+start);
				}
				Q.push(count+1);
			}
		}
	}
}