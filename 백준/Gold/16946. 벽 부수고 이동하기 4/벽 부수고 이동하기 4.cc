#include <iostream>
#include <queue>
#include <set>
using namespace std;
int arr[1001][1001];
int visited[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int result[1000101];

int real[1001][1001];
int BFS(int i, int j);
int N, M = 0;
int main(void)
{

	cin >> N >> M;


	for (int i = 0; i < N; i++)
	{
		string s = "";
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = s[j] - 48;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0&&visited[i][j]==0)
			{
				BFS(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(arr[i][j]==1)
			{
				set<int>s;
				real[i][j] += 1;
				for (int k = 0; k < 4; k++)//1인 경우 동서남북으로 탐색해라
				{
					if (i + dx[k] >= 0 && i + dx[k] < N && j + dy[k] >= 0 && j + dy[k] < M&&arr[i + dx[k]][j + dy[k]] >= 10)
					{
						s.insert(arr[i + dx[k]][j + dy[k]] - 10);
					}
				}
				for (auto t : s)
				{
					real[i][j] += result[t];
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << real[i][j]%10;
		}
		cout << endl;
	}

	return 0;
}

int BFS(int i, int j)
{
	int count = 0;
	visited[i][j] = 1;
	queue<pair<int,int>>q;
	q.push({ i,j });
	
	while (!q.empty())
	{
		count++;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (x+dx[i]>=0&&x+dx[i]<N&& y + dy[i]>=0&& y + dy[i] <M&&visited[x + dx[i]][y + dy[i]] == 0&&arr[x + dx[i]][y + dy[i]]==0)
			{
				visited[x + dx[i]][y + dy[i]] = 1;
				q.push({ x + dx[i], y + dy[i] });
			}
		}
	}

	if (arr[i][j] <10)
	{
		result[i * M + j] = count;
		q.push({ i,j });
		arr[i][j] = i * M + j + 10;
	}
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			if (x + dx[k] >= 0 && x + dx[k] < N && y + dy[k] >= 0 && y + dy[k] < M && visited[x + dx[k]][y + dy[k]] == 1 && arr[x + dx[k]][y + dy[k]] == 0)//방문된 곳을 첫번째로 초기화시킴.
			{
				arr[x + dx[k]][y + dy[k]] = i*M+j+10;
				q.push({ x + dx[k], y + dy[k] });
			}
		}
	}
	return count;
}