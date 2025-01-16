#include <iostream>

using namespace std;

int arr[100001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int M = 0;

	cin >> N>>M;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = 0; i < M; i++)
	{
		int num1 = 0;
		int num2 = 0;
		cin >> num1 >> num2;
		cout << arr[num2] - arr[num1 - 1]<<'\n';
	}



	return 0;
}