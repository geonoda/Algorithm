#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr;
int result[1000000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		for (int j = arr.size()-1; j >= 0; j--)
		{
			if (arr[j].first < num)
			{
				if (result[arr[j].second] == 0)
				{
					result[arr[j].second] = num;
					arr.pop_back();
				}
			}
			else
			{
				break;
			}
		}
		arr.push_back({ num,i });
	}

	for (int i = 0; i < N; i++)
	{
		if (result[i] == 0)
		{
			cout << -1 << " ";
		}
		else
		{
			cout << result[i] << " ";
		}
	}
	return 0;
}// 3 5 2 3 7