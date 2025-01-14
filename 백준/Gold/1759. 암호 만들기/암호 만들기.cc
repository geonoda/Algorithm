#include <iostream>
#include <algorithm>
using namespace std;

char arr[16];
int visited[16];
char result[16];
void DFS(int start, int num1, int num2,int count);

int L = 0;
int C = 0;

int main(void)
{
	
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> arr[i];
		result[i] = ' ';
	}

	sort(arr, arr + C);

	DFS(0,0,0,0);

	return 0;
}

void DFS(int start, int num1, int num2, int count)
{
	if (count == L)
	{
		if (num1 >= 1 && num2 >= 2)
		{
			for (int i = 0; i < C; i++)
			{
				if (result[i] != ' ')
				{
					cout << result[i];
				}
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = start; i < C; i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				result[i] = arr[i];
				if (arr[i] == 'a' || arr[i] == 'e' ||arr[i] == 'i'||arr[i] == 'o'||arr[i] == 'u')
				{
					DFS(i,num1+1, num2, count + 1);
				}
				else
				{
					DFS(i,num1, num2+1, count + 1);
				}
				result[i] = ' ';
				visited[i] = 0;
			}
		}
	}
}