#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int A[500001];
int main(void)
{
	int N = 0;
	unordered_map<int, int> hashMap;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		A[i] = num;
		
		hashMap[num] = i;
		
	}

	sort(A, A + N);
	
	int max = 0;

	for (int i = 0; i < N; i++)
	{
		if (A[i] != A[i + 1])
		{
			if (max < hashMap[A[i]] - i)
			{
				max = hashMap[A[i]] - i;
			}
		}
	}
	cout << max+1;
}