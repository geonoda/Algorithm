#include <iostream>
#include<queue>
#include <algorithm>
using namespace std;

int visited[300000];
int result[100000];
int DFS(int R);
int a=0;
int b=0;
int c=0;
int count1=1;
vector<int> G[100001];
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>a>>b>>c;
	
	for(int i=0; i<b; i++)
	{
		int num1=0;
		int num2=0;
		cin>>num1>>num2;
		G[num1].push_back(num2);
		G[num2].push_back(num1);
	}
	for(int i=0; i<a; i++)
	{
		sort(G[i].begin(), G[i].end());
	}
	result[c]=count1;
	DFS(c);
	
	
	for(int i=1; i<=a; i++){
		cout<<result[i]<<'\n';
	}
	return 0;
}

int DFS(int R)
{
	visited[R]=1;
	for(int i=0; i<G[R].size(); i++)
	{
		int k=G[R][i];
		if(visited[k]==0)
		{
			count1++;
			result[k]=count1;
			DFS(k);
		}
		
	}
	
	return 0;
	
}