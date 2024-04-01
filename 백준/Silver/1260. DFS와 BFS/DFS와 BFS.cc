#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> V[1001];
int visited1[1001];
int visited2[1001];
queue<int> Q;

void DFS(int R);
void BFS(int R);

int a=0;
int b=0;
int c=0;

int result1[1001];
int result2[1001];

int count1=0;
int count2=0;

int main(void)
{
	cin>>a>>b>>c;
	
	for(int i=0; i<b; i++)
	{
		int num1=0;
		int num2=0;
		cin>>num1>>num2;
		V[num1].push_back(num2);
		V[num2].push_back(num1);
	}
	
	for(int i=1; i<=a; i++)
	{
		sort(V[i].begin(),V[i].end());
	}
	
	BFS(c);
	
	DFS(c);
	
	for(int i=1; i<=count2; i++)
	{
		cout<<result2[i]<<" ";
	}
	cout<<endl;
	for(int i=1; i<=count1; i++)
	{
		cout<<result1[i]<<" ";
	}
	
	return 0;
}

void BFS(int R)
{
	visited1[R]=1;
	Q.push(R);
	count1++;
	result1[count1]=R;
	while(!Q.empty())
	{
		int k=Q.front();
		Q.pop();
		for(int i=0; i<V[k].size(); i++)
		{
			int temp=V[k][i];
			if(visited1[temp]==0)
			{
				visited1[temp]=1;
				Q.push(temp);
				count1++;
				result1[count1]=temp;
			}
		}	
	}
}

void DFS(int R)
{
	visited2[R]=1;
	count2++;
	result2[count2]=R;
	for(int i=0; i<V[R].size(); i++)
	{
		int temp=V[R][i];
		if(visited2[temp]==0)
		{
			visited2[temp]=1;
			DFS(temp);
		}
	}
}
