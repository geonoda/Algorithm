#include <iostream>
#include <queue>

using namespace std;
queue<int>q;

int main(void)
{
	int N = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	if (N == 1)
	{
		cout << 1;
		return 0;
	}

	while (true)
	{
		q.pop();

		int num = q.front();
		q.pop();
		if (q.empty())
		{
			cout << num;
			break;
		}
		else
		{
			q.push(num);
		}
	}

	return 0;
}