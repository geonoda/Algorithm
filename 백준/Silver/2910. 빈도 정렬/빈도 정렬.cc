#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,pair<int,int>> &a, pair<int, pair<int, int>>& b)
{
	if (a.second.first == b.second.first)
	{
		return a.second.second < b.second.second;
	}
	else
	{
		return a.second.first > b.second.first;
	}
}

int main(void)
{
	unordered_map<int, pair<int, int>> hashMap;

	int N = 0;
	int M = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int num = 0;

		cin >> num;
		
		hashMap[num].first++;

		if (hashMap[num].first == 1)
		{
			hashMap[num].second=i;
		}
	}
	vector<pair<int, pair<int, int>>> V(hashMap.begin(), hashMap.end());
	sort(V.begin(), V.end(), cmp);

	for (int i = 0; i<V.size(); i++)
	{
		for (int j = 0; j<V[i].second.first; j++)
		{
			cout << V[i].first<<" ";
		}
	}

	return 0;
}