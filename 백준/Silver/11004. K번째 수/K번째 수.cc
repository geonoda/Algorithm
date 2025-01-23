#include <iostream>
#include <algorithm>

using namespace std;
int arr[5000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cout << arr[K - 1];
	return 0;
}