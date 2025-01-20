#include <iostream>
#include <stack>

using namespace std;

int arr[100001];
int result[100001];

int main(void)
{
	stack<int> st;
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{	
		cin >> arr[i];
	}

	int k = 1;
	int count = 0;
	int sig = 0;

	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			if (st.empty())
			{
				st.push(k);
				k++;
				result[count] = 1;
				count++;
			}
			if (k > n)
			{
				if (arr[i] != st.top())
				{
					sig = 1;
					break;
				}
			}
			if (arr[i] != st.top())
			{
				st.push(k);
				k++;
				result[count] = 1;
				count++;
			}
			else
			{
				st.pop();
				result[count] = 0;
				count++;
				break;
			}
		}
	}

	if (sig == 1)
	{
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			if (result[i] == 0)
			{
				cout << '-' << '\n';
			}
			else
			{
				cout << '+' << '\n';
			}
		}
	}

	return 0;
}