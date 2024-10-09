#include <iostream>

using namespace std;

int arr[51][51];

int main(void)
{
	int N = 0;
	int M = 0;
	cin >> N >> M;

	int sx, sy, dir = 0;

	cin >> sx >> sy >> dir;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int count = 0;
	while (true)
	{
		if (arr[sx][sy] == 0)//있으면 지우고
		{
			arr[sx][sy] = 2;
			count++;
		}
		if ((arr[sx + 1][sy] != 0||sx+1==N) && (arr[sx - 1][sy] != 0||sx-1==-1) && (arr[sx][sy + 1] != 0||sy+1==M) && (arr[sx][sy - 1] != 0||sy-1==-1))//주변에 아무것도 청소할게 없다면 이동
		{
			if (dir == 0)
			{
				sx++;
				if (sx > N - 1||arr[sx][sy]==1)
				{
					break;
				}
			}
			else if (dir == 1)
			{
				sy--;
				if (sy < 0 || arr[sx][sy] == 1)
				{
					break;
				}
			}
			else if (dir == 2)
			{
				sx--;
				if (sx < 0 || arr[sx][sy] == 1)
				{
					break;
				}
			}
			else if (dir == 3)
			{
				sy++;
				if (sy > M - 1 || arr[sx][sy] == 1)
				{
					break;
				}
			}
		}
		else//청소할게 있다면??
		{
			while (true)
			{
				dir = (dir)-1;
				if (dir < 0)
				{
					dir = 4 + dir;
				}
				if (arr[sx - 1][sy]== 0 && dir == 0&&sx-1>-1)
				{
					sx--;
					break;
				}
				else if (arr[sx][sy - 1] == 0 && dir == 3 && sy - 1 > -1)
				{
					sy--;
					break;
				}
				else if (arr[sx + 1][sy] == 0 && dir == 2 && sx + 1 < N)
				{
					sx++;
					break;
				}
				else if (arr[sx][sy + 1] == 0 && dir == 1&&sy+1<M)
				{
					sy++;
					break;
				}
			}
		}
	}
	cout << count;

	return 0;
}