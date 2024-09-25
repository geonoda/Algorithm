#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

string result[500001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

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
			result[count] = temp;
			count ++;
		}
		
	}

	sort(result, result+count);

	cout << count<<endl;
	for (int i = 0; i < count; i++)
	{
		cout << result[i]<<'\n';
	}

	return 0;
}