#include <iostream>

using namespace std;

int arr[1001][1001];

int d[4] = { 1,-1,-2,2 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

void DFS(int x, int y, int dir, int count, int sum);
void DFS2(int x, int y);
int N = 0;
int M = 0;
int max1 = 0;

int main(void)
{

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			DFS(i, j, 0, 1, arr[i][j]);//상 하 좌 우  1, -1, -2, 2
			DFS2(i, j);
		}
	}

	cout << max1;
	return 0;
}

void DFS(int x, int y, int dir, int count, int sum)
{
	if (count < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < N && y + dy[i] < M)
			{
				if (dir != (-d[i]))
				{
					DFS(x + dx[i], y + dy[i], d[i], count + 1, sum + arr[x + dx[i]][y + dy[i]]);
				}
			}
		}
	}
	else
	{
		if (sum > max1)
		{
			max1 = sum;
		}
	}

}

void DFS2(int x, int y)
{
	int sig[4] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < N && y + dy[i] < M)
		{
			sig[i] = 0;
		}
		else
		{
			sig[i] = 1;
		}
	}

	if (sig[0] == 0 && sig[1] == 0)
	{
		int sum = arr[x][y] + arr[x - 1][y] + arr[x + 1][y];
		if (sig[2] == 1)
		{
			//왼쪽만뺌.
			sum += arr[x][y + 1];
			if (sum > max1)
			{
				max1 = sum;
			}
		}
		else if (sig[3] == 1)
		{
			//오른쪽만뻄
			sum += arr[x][y - 1];
			if (sum > max1)
			{
				max1 = sum;
			}
		}
		else
		{
			int temp1 = sum + arr[x][y + 1];
			int temp2 = sum + arr[x][y - 1];

			if (temp1 > max1)
			{
				max1 = temp1;
			}
			if (temp2 > max1)
			{
				max1 = temp2;
			}
			//둘다봄.
		}
	}
	if (sig[2] == 0 && sig[3] == 0)
	{
		int sum = arr[x][y] + arr[x][y - 1] + arr[x][y + 1];
		if (sig[0] == 1)
		{
			//위만뺌
			sum += arr[x - 1][y];
			if (sum > max1)
			{
				max1 = sum;
			}
		}
		else if (sig[1] == 1)
		{
			//아래만뺌
			sum += arr[x + 1][y];
			if (sum > max1)
			{
				max1 = sum;
			}
		}
		else
		{
			int temp1 = sum + arr[x - 1][y];
			int temp2 = sum + arr[x + 1][y];

			if (temp1 > max1)
			{
				max1 = temp1;
			}
			if (temp2 > max1)
			{
				max1 = temp2;
			}
			//둘다봄.
		}
	}

}