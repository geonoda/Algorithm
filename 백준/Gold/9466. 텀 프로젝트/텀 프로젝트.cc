#include <iostream>
#include <vector>

using namespace std;
void DFS(int num);
int arr[100001];
int visited[100001];
int done[100001];
int count1 = 0;
int main(void)
{
	int T,N = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		
		cin >> N;
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[j];
		}

		for (int j = 1; j <= N; j++)
		{
			DFS(j);
		}
		cout << N-count1<<endl;
		count1 = 0;
		for (int j = 1; j <= 100000; j++)
		{
			arr[j] = 0;
			visited[j] = 0;
			done[j] = 0;
		}
	}
	return 0;
}

void DFS(int num)
{
	int next = arr[num];
	visited[num] = 1;
	if (visited[next] == 0)//방문은 했는데
	{
		DFS(next);
	}
	else if(done[next]==0)//아직 마무리를 짓지 않았으면 사이클이 있다고 판단
	{
		int temp = num;
		
		while (true)
		{
			temp = arr[temp];
			count1++;
			if (temp == num)
			{
				break;
			}
		}
	}
	done[num] = 1;
}