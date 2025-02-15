#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>v[10001];
int visited[10001];

void DFS(int num);
int count1 = 1;
vector<int>result;

int main(void)
{
	int N = 0;
	int M = 0;
	int max = 0;
	cin >> N >> M;

	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2;
		v[num2].push_back(num1);
	}

	for (int i = 1; i <= N; i++)
	{
		visited[i] = 1;
		DFS(i);

		if (count1 > max)
		{
			max = count1;
			result.clear();
			result.push_back(i);
		}
		else if (count1 == max)
		{
			result.push_back(i);
		}
		for (int i = 1; i <= N; i++)
		{
			visited[i] = 0;
		}
		count1 = 1;
	}

	sort(result.begin(), result.end());


	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<<" ";
	}

	return 0;
}

void DFS(int num)
{
	for (int i = 0; i < v[num].size(); i++)
	{
		if (visited[v[num][i]]==0)
		{
			visited[v[num][i]] = 1;
			count1++;
			DFS(v[num][i]);
			
		}
	}
}