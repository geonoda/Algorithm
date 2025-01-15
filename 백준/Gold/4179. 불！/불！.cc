#include <iostream>
#include <queue>;

using namespace std;

char arr[1001][1001];
int visited[1001][1001][2];
int visited2[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
priority_queue<pair<pair<int, char>, pair<int, int>>>q;
void BFS();


int R = 0;
int C = 0;
int main(void)
{


	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'J')
			{
				q.push({ {0,'J'},{i, j} });
			}
			if (arr[i][j] == 'F')
			{
				q.push({ {0,'F'},{i, j} });
			}
			visited[i][j][1] = 987654321;
		}
	}

	BFS();

	return 0;
}

void BFS()
{
	int sig = 0;
	int result = 0;
	while (!q.empty())
	{
		int count = -q.top().first.first;
		char c = q.top().first.second;

		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();

		if (c == 'F')
		{
			visited[x][y][0] = 1;
		}

		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < R && +dy[i] < C && c == 'J' && visited[x][y][1] > count && visited[x + dx[i]][y + dy[i]][1] > count+1 && visited2[x + dx[i]][y + dy[i]] == 0 && arr[x + dx[i]][y + dy[i]] == '.')
			{
				visited2[x + dx[i]][y + dy[i]] = 1;
				q.push({ {-(count + 1),'J'},{x + dx[i],y + dy[i]} });

			}
			if ((x + dx[i] == -1 || y + dy[i] == -1 || x + dx[i] == R || y + dy[i] == C) && c == 'J' && visited[x][y][1] > count)
			{
				sig = 1;
				result = count + 1;
			}
			if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < R && +dy[i] < C && c == 'F' && visited[x + dx[i]][y + dy[i]][0] == 0 && (arr[x + dx[i]][y + dy[i]] =='.'|| arr[x + dx[i]][y + dy[i]] == 'J'))
			{
				visited[x + dx[i]][y + dy[i]][0] = 1;
				visited[x + dx[i]][y + dy[i]][1] = count+1;
				/*for (int l = 0; l < R; l++)
				{
					for (int j = 0; j < C; j++)
					{
						cout << visited[l][j][0]<< " ";
					}
					cout << endl;
				}*/
				q.push({ {-(count + 1),'F'},{x + dx[i],y + dy[i]} });
			}
		}
		if (sig == 1)
		{
			break;
		}
	}
	if (sig == 0)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << result;
	}
}