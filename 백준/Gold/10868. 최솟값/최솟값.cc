#include <iostream>

using namespace std;
int arr[1000000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M = 0;
	cin >> N >> M;

	int count = 1;
	int lef = 0;

	for (int i = 0; i < 1000000; i++)
	{
		arr[i] = 1234567891;
	}

	while (count < N)
	{
		count *= 2;
	}
	lef = count - 1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i+count];
	}

	while (count>0)
	{
		count = count / 2;
		for (int i = count; i < count * 2; i++)
		{
			if (arr[i * 2] < arr[i * 2 + 1])
			{
				arr[i] = arr[i * 2];
			}
			else
			{
				arr[i] = arr[i * 2+1];
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a, b = 0;
		cin >> a >> b;

		int start = a+lef;
		int end = b+lef;
		int min = 1234567891;

		while (start <= end)
		{
			//cout << start << end<<endl;
			if (start % 2 == 1)
			{
				if (arr[start] < min)
				{
					min = arr[start];
				}
			}

			if (end % 2 == 0)
			{
				if (arr[end] < min)
				{
					min = arr[end];
				}
			}
			start = (start + 1) / 2;
			end = (end - 1) / 2;
		}
		cout << min << '\n';
	}

	return 0;
}