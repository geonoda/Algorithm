#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void)
{
	set<pair<int, int>>hashSet;
	vector<pair<int, int>>V;
	int N = 0;
	int count = 0;
	cin >> N;

	for (int i = 0; i < N; i ++)
	{
		int x, y = 0;
		cin >> x >> y;
		hashSet.insert(make_pair(x, y));
		V.push_back(make_pair(x, y));
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			int x1 = V[i].first;
			int y1 = V[i].second;
			int x2 = V[j].first;
			int y2 = V[j].second;

			if (x1 == x2 || y1 == y2)
			{
				continue;
			}
			else if((hashSet.find({x2,y1}) != hashSet.end()) && (hashSet.find({x1,y2}) != hashSet.end()))
			{
				count++;
			}
		}
	}
	cout << count/2;
	return 0;
}