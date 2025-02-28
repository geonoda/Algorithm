#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[10001];
vector<pair<int,int>>v[10001];
queue<int>q;
int distance1[10001];

int arr2[10001];
vector<pair<int, int>>v2[10001];
int visited[10001];
int main(void)
{
	int N = 0;
	int M = 0;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c = 0;
		cin >> a >> b >> c;
		arr[b]++;
		v[a].push_back({ b,c });
		arr2[a]++;
		v2[b].push_back({ a,c });
	}

	int start, end = 0;
	cin >> start >> end;

	q.push(start);
	while (!q.empty())
	{
		int num = q.front();
		q.pop();
		for (int i = 0; i < v[num].size(); i++)
		{
			arr[v[num][i].first]--;
			if (arr[v[num][i].first] == 0)
			{
				q.push(v[num][i].first);
			}
			if (distance1[v[num][i].first]<distance1[num]+ v[num][i].second)
			{
				distance1[v[num][i].first] = distance1[num] + v[num][i].second;
			}
		}
	}

	q.push(end);
	int count = 0;
	while(!q.empty())
	{
		int num = q.front();
		q.pop();

		for (int i = 0; i < v2[num].size(); i++)
		{
			if (distance1[num] == distance1[v2[num][i].first] + v2[num][i].second)
			{
				if (visited[v2[num][i].first] == 0)
				{
					q.push(v2[num][i].first);
				}
				
				visited[v2[num][i].first] = 1;
				count++;
			}
		}
	}
	cout << distance1[end]<<endl;
	cout << count;

	return 0;
}