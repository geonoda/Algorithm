#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> q;

int visited[100001];

int main(void)
{
	int N = 0;
	int K = 0;

	int time = 0;
	int result = 0;
	int sig = 0;
	cin >> N >> K;

	q.push({ N,0 });

	while(!q.empty())
	{
		int num = q.front().first;
		int count = q.front().second;
		visited[num] = 1;
		q.pop();

		if (num == K&&sig==0)
		{
			time = count;
			sig = 1;
		}

		if (num == K && sig == 1 && time == count)
		{
			result++;
		}
		
		if (num - 1 >= 0&&visited[num-1]==0)
		{
			q.push({ num - 1,count + 1 });
		}
		if (num + 1 <= 100000&& visited[num + 1] ==0)
		{
			q.push({ num + 1,count + 1 });
		}
		if (num * 2 <= 100000&&num*2>=0&&visited[num*2] == 0)
		{
			q.push({ num * 2,count + 1 });
		}
		
	}

	cout << time << endl;
	cout << result;

	return 0;
}