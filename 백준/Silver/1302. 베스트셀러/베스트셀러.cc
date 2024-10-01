#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void)
{
	unordered_map<string, int> hashMap;
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string temp = "";
		cin >> temp;
		hashMap[temp]++;
	}

	vector<pair<string, int>> V(hashMap.begin(), hashMap.end());

	sort(V.begin(),V.end());

	int max = 0;
	string result = "";
	for (auto p : V)
	{
		if (p.second > max)
		{
			max = p.second;
			result = p.first;
		}
	}

	cout << result;

	return 0;
}