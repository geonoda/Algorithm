#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int visited[201][201];
vector<int> result;
void BFS();
struct k
{
	int a;
	int b;
	int c;
};
queue < k > q;
int A, B, C;
int main(void)
{
	
	cin >> A >> B >> C;
	BFS();
	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " " ;
	}

	return 0;
}

void BFS()
{
	q.push({ 0,0,C });
	visited[0][0] = 1;
	while (!q.empty())
	{
		if (q.front().a == 0)
		{
			result.push_back(q.front().c);
		}
		if (q.front().a != 0)
		{
			if (q.front().b < B)
			{
				int num = q.front().a - (B - q.front().b);
				if (num > 0)
				{
					if (visited[num][B] == 0)
					{
						visited[num][B] = 1;
						q.push({ num,B,q.front().c });
					}
				}
				else
				{
					if (visited[0][q.front().a + q.front().b]==0)
					{
						visited[0][q.front().a + q.front().b] = 1;
						q.push({ 0,q.front().a + q.front().b,q.front().c });
					}
				}
			}

			if (q.front().c < C)
			{
				int num = q.front().a - (C - q.front().c);
				if (num > 0)
				{
					if (visited[num][q.front().b] == 0)
					{
						visited[num][q.front().b] = 1;
						q.push({ num,q.front().b,C});
					}
				}
				else
				{
					if (visited[0][q.front().b] == 0)
					{
						visited[0][q.front().b] = 1;
						q.push({ 0,q.front().b,q.front().a+q.front().c });
					}
				}
			}
		}
		if (q.front().b != 0)
		{
			if (q.front().a < A)
			{
				int num = q.front().b - (A - q.front().a);
				if (num > 0)
				{
					if (visited[A][num] == 0)
					{
						visited[A][num] = 1;
						q.push({ A,num,q.front().c });
					}
				}
				else
				{
					if (visited[q.front().a + q.front().b][0] == 0)
					{
						visited[q.front().a + q.front().b][0] = 1;
						q.push({ q.front().a + q.front().b,0,q.front().c });
					}
				}
			}

			if (q.front().c < C)
			{
				int num = q.front().b - (C - q.front().c);
				if (num > 0)
				{
					if (visited[q.front().a][num] == 0)
					{
						visited[q.front().a][num] = 1;
						q.push({ q.front().a,num,C });
					}
				}
				else
				{
					if (visited[q.front().a][0] == 0)
					{
						visited[q.front().a][0] = 1;
						q.push({ q.front().a,0,q.front().b + q.front().c });
					}
				}
			}
		}
		if (q.front().c != 0)
		{
			if (q.front().a < A)
			{
				int num = q.front().c - (A - q.front().a);
				if (num > 0)
				{
					if (visited[A][q.front().b] == 0)
					{
						visited[A][q.front().b] = 1;
						q.push({ A,q.front().b,num });
					}
				}
				else
				{
					if (visited[q.front().a + q.front().c][q.front().b] == 0)
					{
						visited[q.front().a + q.front().c][q.front().b] = 1;
						q.push({ q.front().a + q.front().c,q.front().b,0 });
					}
				}
			}

			if (q.front().b < B)
			{
				int num = q.front().c - (B - q.front().b);
				if (num > 0)
				{
					if (visited[q.front().a][B] == 0)
					{
						visited[q.front().a][B] = 1;
						q.push({ q.front().a,B,num });
					}
				}
				else
				{
					if (visited[q.front().a][q.front().b + q.front().c] == 0)
					{
						visited[q.front().a][q.front().b + q.front().c] = 1;
						q.push({ q.front().a,q.front().b + q.front().c,0 });
					}
				}
			}
		}
		q.pop();
	}
}