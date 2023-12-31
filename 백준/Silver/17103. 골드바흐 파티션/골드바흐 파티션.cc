#include <iostream>
#include <stdlib.h>

using namespace std;
int arr[1000000] = { 0 };
int main(void)
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int MAX_SIZE = 1000000;
	int b[100000] = { 0 };
	int m = 0;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	for (int i = 2; i * i <MAX_SIZE ; i++) {
			for (int j = i * i; j < MAX_SIZE; j = j + i) {
				if (arr[j] == 0) {
					arr[j] = 1;
				}
			}
		}
		
	for (int k = 0; k < m; k++)
	{
		

		int count = 0;
		arr[1] = 1;
		for (int i = 2; i < b[k]; i++)
		{
			int num = 0;
			if (arr[i] == 0)
			{
				num = b[k] - i;

				if (arr[num] == 0)
				{
					count++;
					if (i == b[k] - i)
					{
						count++;
					}
				}
			}
		}
		cout << count / 2 << '\n';
		count = 0;
	}



	return 0;
}