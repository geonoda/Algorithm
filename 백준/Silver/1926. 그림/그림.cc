#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<int> v[1000];
int visited[501][501];

int DFS(int x, int y,int num);
int n = 0;
int m = 0;
int main(void)
{
	cin >> n >> m;

	int num = 0;
	int max = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			v[i].push_back(num);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0&&v[i][j]==1)
			{
				visited[i][j] = 1;
				int result=DFS(i,j,1);
				count++;
				if (result > max)
				{
					max = result;
				}
			}
		}
	}
	cout << count << endl;
	cout << max;
	
	return 0;
}

int DFS(int x, int y, int num)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] > -1 && y + dy[i] > -1 && x + dx[i] < n && y + dy[i] < m&&visited[x+dx[i]][y+dy[i]]==0&& v[x+dx[i]][y+dy[i]] == 1)
		{
			visited[x + dx[i]][y + dy[i]] = 1;
			num = DFS(x + dx[i], y + dy[i], num + 1);
		}
	}
	return num;
}