#include <iostream>
#include <queue>

using namespace std;

priority_queue<int>ppq;
priority_queue<int>mpq;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		if (num != 0)
		{
			if (num < 0)
			{
				mpq.push(num);
			}
			else
			{
				ppq.push(-num);
			}
		}
		else
		{
			if (!ppq.empty() || !mpq.empty())
			{
				if (ppq.empty())
				{
					cout << mpq.top() << '\n';
					mpq.pop();
				}
				else if (mpq.empty())
				{
					cout<< -ppq.top() << '\n';
					ppq.pop();
				}
				else
				{
					if (ppq.top() > mpq.top())
					{
						cout << -ppq.top() << '\n';
						ppq.pop();
					}
					else
					{
						cout << mpq.top() << '\n';
						mpq.pop();
					}
				}
			}
			else
			{
				cout << 0<<'\n';
			}
			
		}
	}
	return 0;
}