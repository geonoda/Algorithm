#include <iostream>

using namespace std;

long long arr[1000001];
long long result[1000];

int main(void)
{
	int N = 0;
	int M = 0;

	long long count = 0;

	cin >> N >> M;

	for (long long i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
		if (arr[i] % M == 0)//나누어 떨어짐.
		{
			count++;// 자기 혼자서도 나머지가 0임.
		}
		result[arr[i] % M]++;
	}

	for (int i = 0; i < 1000; i++)
	{
		if (result[i] > 1)
		{
			count += result[i] * (result[i] - 1) / 2;
		}
	}

	cout << count;

	return 0;
}
