#include <iostream>
#include <set>
using namespace std;
void Union(int a,int b);
int Find(int num);
string arr[1001];
int parent[1000001];
set<int>set1;
int main(void)
{
	int N, M = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= 1000000; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j-1] == 'D')
			{
				Union((i*M)+j,(i-1)*M+j);
			}
			else if (arr[i][j-1] == 'U')
			{
				Union((i - 2) * M + j, (i - 1) * M + j);
			}
			else if (arr[i][j-1] == 'L')
			{
				Union((i - 1) * M + j-1, (i - 1) * M + j);
			}
			else if (arr[i][j-1] == 'R')
			{
				Union((i - 1) * M + j + 1, (i - 1) * M + j);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			Find((i - 1) * M + j);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			set1.insert(parent[(i - 1) * M + j]);
			//cout << parent[(i - 1) * M + j] << " ";
		}
		//cout << endl;
	}
	cout << set1.size();


	return 0;
}

int Find(int num)
{
	if (parent[num] == num)
	{
		return num;
	}
	else
	{
		parent[num] = Find(parent[num]);
	}
	return parent[num];
}

void Union(int a, int b)
{
	int num1 = Find(a);
	int num2 = Find(b);

	parent[num2] = num1;
}

//각 좌표마다 갈 수 있는 safe존을 확인한다?? 시간초과아님?
//