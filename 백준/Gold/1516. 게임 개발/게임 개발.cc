#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[501];
vector<int>v[501];
queue<int>q;

int distance1[501];
int wait[501];
int main(void)
{
	int N = 0;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int a, b= 0;
		cin >> a;
		distance1[i] = a;
		while (true)
		{
			cin >> b;
			if (b == -1)
			{
				break;
			}
			v[b].push_back(i);
			arr[i]++;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		for (int i = 0; i < v[num].size(); i++)
		{
			arr[v[num][i]]--;
			if (wait[v[num][i]] < distance1[num])
			{
				wait[v[num][i]] = distance1[num];
			}
			if (arr[v[num][i]] == 0)
			{
				q.push(v[num][i]);
				distance1[v[num][i]] += wait[v[num][i]];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << distance1[i]<<"\n";
	}

	return 0;
}