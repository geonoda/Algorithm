#include <iostream>
#include <queue>
#include <vector>

using namespace std;
priority_queue < pair<int, int>>pq;
vector<pair<int, int>>v;

int DP[101];

int main(void)
{
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num1 = 0;
		int num2 = 0;
		cin >> num1 >> num2;
		if (num1 > num2)
		{
			pq.push({ -num1,-num2 });
		}
		else
		{
			pq.push({ -num2,-num1 });
		}
	}

	while (!pq.empty())
	{
		//cout << pq.top().first << " " << pq.top().second << endl;
		v.push_back({ -pq.top().first,-pq.top().second });
		pq.pop();
	}

	/*for (int i =0; i<v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}*/

	for (int i = 1; i < N; i++)
	{
		for (int j = i-1; j >=0; j--)
		{
			if ((v[i].first >= v[j].first && v[i].second >= v[j].second) || (v[i].second >= v[j].first && v[i].first >= v[j].second))
			{
				
				if (DP[i] < DP[j] + 1)
				{
					DP[i] = DP[j] + 1;
				}
				
			}
		}
	}



	int max = 0;

	for (int i = 0; i < N; i++)
	{
		//cout << DP[i] << endl;
		if (DP[i] > max)
		{
			max = DP[i];
		}
	}
	cout << max+1;
	return 0;
}