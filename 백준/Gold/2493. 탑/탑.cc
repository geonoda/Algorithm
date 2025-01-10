#include <iostream>
#include <stack>

using namespace std;

stack<pair<int,int>> s;
int result[500001];

int main(void)
{
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;

		if (s.empty())
		{
			s.push({ num,i+1 });
			result[i] = 0;
		}
		else
		{
			while (true)
			{
				if (s.top().first < num)
				{
					s.pop();
					if (s.empty())
					{
						s.push({ num,i + 1 });
						result[i] = 0;
						break;
					}
				}
				else
				{
					result[i] = s.top().second;
					s.push({ num,i+1 });
					break;
				}
			}
		}	
	}

	for (int i = 0; i < N; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}