#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(void)
{
	unordered_set<string> hashSet;
	int N = 0;
	int M = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string temp = "";
		cin >> temp;
		hashSet.insert(temp);
	}

	int count = 0;
	for (int i = 0; i < M; i++)
	{
		string temp = "";
		cin >> temp;
		if (hashSet.find(temp) != hashSet.end())
		{
			count++;
		}
	}

	cout << count;
	return 0;
}