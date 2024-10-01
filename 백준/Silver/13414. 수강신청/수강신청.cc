#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.second < b.second;
}

int main(void)
{
	unordered_map<string, int> hashMap;
	
	int K = 0;
	int L = 0;
	cin >> K >> L;

	int count = 0;

	for (int i = 0; i < L; i++)
	{
		string temp = "";
		cin >> temp;

		hashMap[temp] = i;
		count = i;
	}
	vector<pair<string, int>> V(hashMap.begin(), hashMap.end());

	sort(V.begin(), V.end(), cmp);

	if (V.size() < K)
	{
		K = V.size();
	}

	for (int i = 0; i < K; i++)
	{
		cout<<V[i].first<<'\n';
	}

	return 0;
}