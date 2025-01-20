#include <iostream>
#include <queue>

using namespace std;

int arr[20][20];
int DP[20][20][4];

priority_queue<pair<int, int>>pq;

int main(void)
{
	int N = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	DP[1][2][1] = 1;

	for (int i = 1; i <=N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= 3; k++)
			{
				if (arr[i][j] == 0)
				{
					if (k == 1)
					{
						if (DP[i][j][1] < DP[i][j - 1][1] + DP[i][j - 1][2])
						{
							if (j - 2 >= 0&&arr[i][j - 1] == 0&& arr[i][j - 2] == 0)
							{
								DP[i][j][1] += DP[i][j - 1][1];
							}
							if (j - 2 >= 0&&arr[i][j - 1] == 0 && arr[i][j - 2] == 0 && arr[i - 1][j - 2] == 0 && arr[i - 1][j - 1] == 0)
							{
								DP[i][j][1] += DP[i][j - 1][2];
							}
							
						}
					}
					else if (k == 2)
					{
						if (DP[i][j][2] < DP[i - 1][j - 1][1] + DP[i - 1][j - 1][2] + DP[i - 1][j - 1][3])
						{
							if (arr[i][j] == 0 && arr[i][j - 1] == 0 && arr[i-1][j - 1] == 0 && arr[i - 1][j] == 0)
							{
								if (i - 2 >= 0 && arr[i - 1][j - 1] == 0 && arr[i - 2][j - 1] == 0)
								{
									DP[i][j][2]+= DP[i - 1][j - 1][3];
								}
								if (i-2>=0&&j-2>=0&&arr[i-1][j - 1] == 0 && arr[i-1][j - 2] == 0 && arr[i - 2][j - 2] == 0 && arr[i - 2][j - 1] == 0)
								{
									DP[i][j][2] += DP[i - 1][j - 1][2];
								}
								if (j-2>=0&&arr[i - 1][j - 1] == 0 && arr[i - 1][j - 2] == 0)
								{
									DP[i][j][2] += DP[i - 1][j - 1][1];
								}
							}
						}
					}
					else if (k == 3)
					{
						if (DP[i][j][3] < DP[i - 1][j][3] + DP[i - 1][j][2])
						{
							if (i-2>=0&&arr[i][j] == 0 && arr[i - 1][j] == 0 && arr[i - 2][j] == 0)
							{
								DP[i][j][3] += DP[i - 1][j][3];
							}
							if (i-2>=0&&arr[i][j] == 0 && arr[i - 1][j] == 0 && arr[i - 2][j] == 0 && arr[i - 1][j - 1] == 0 && arr[i - 2][j - 1] == 0)
							{
								DP[i][j][3] += DP[i - 1][j][2];
							}
						}
					}
				}
				
				
			}
		}
	}
	/*for (int k = 1; k <= 3; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << DP[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	
	cout << DP[N][N][1] + DP[N][N][2] + DP[N][N][3];
	 
	return 0;
}