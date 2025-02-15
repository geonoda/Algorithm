#include <iostream>
#include <vector>

using namespace std;
vector<int>v[20001];
int visited[20001];
int G[20001];
int sig = 0;


void DFS(int num);

int main(void)
{
	int K = 0;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int V = 0;
		int E = 0;
		cin >> V >> E;
		for (int j = 0; j < E; j++)
		{
			int num1 = 0;
			int num2 = 0;
			cin >> num1 >> num2;
			v[num1].push_back(num2);
			v[num2].push_back(num1);
		}
		for (int k = 1; k <= V; k++)
		{
			if (sig == 0)
			{
				if (visited[k] == 0)
				{
					DFS(k);
				}
			}
			else
			{
				break;
			}
		}
		if (sig == 0)
		{
			cout << "YES"<<endl;
		}
		else
		{
			cout << "NO"<<endl;
		}

		sig = 0;
		for (int k = 0; k < 20001; k++)
		{
			G[k] = 0;
			visited[k] = 0;
			while (!v[k].empty())
			{
				v[k].pop_back();
			}
		}
	}
	return 0;
}

void DFS(int num)
{
	visited[num] = 1;
	for (int i = 0; i < v[num].size(); i++)
	{
		if (visited[v[num][i]] == 0)
		{
			G[v[num][i]] = (G[num] + 1) % 2;
			DFS(v[num][i]);
		}
		else
		{
			if (G[num] == G[v[num][i]])
			{
				sig = 1;
				break;
			}
		}
	}
}