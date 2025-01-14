#include <iostream>
#include <algorithm>

using namespace std;

int arr[200001];

int main(void)
{
	int N = 0;
	int C = 0;

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int L = 1;
	int R = arr[N - 1] - arr[0];
	int result = 0;

	while(L<=R)
	{
		int mid = (L + R) / 2;
		int count = 1;

		int pre = arr[0];

		for (int i = 1; i < N; i++)
		{
			if (arr[i] -pre  >= mid)
			{
				pre = arr[i];
				count++;
			}
			
		}

		if (count >= C)
		{
			result = mid;
			L = mid + 1;
		}
		else
		{
			R = mid - 1;
		}
	}

	cout << result;


	return 0;
} // 1 2 4 8 9