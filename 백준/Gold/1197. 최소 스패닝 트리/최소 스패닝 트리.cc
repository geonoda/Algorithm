#include<iostream>
#include <queue>
using namespace std;
priority_queue<pair<int, pair<int, int>>>pq;
int arr[10001];
void Union(int a, int b);
int Find(int num);
int main(void)
{
	int V = 0;
	int E = 0;
	cin >> V >> E;
	int count = 0;
	int sum = 0;
	for (int i = 1; i <= V; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < E; i++)
	{
		int num1,num2,num3 = 0;
		cin >> num1 >> num2 >> num3;
		pq.push({ -num3,{num1,num2} });
	}

	while (count < V-1)
	{
		if (pq.empty())
		{
			break;
		}
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		if (Find(a) != Find(b))
		{
			Union(a, b);
			count++;
			sum+= -pq.top().first;
		}
		pq.pop();
	}

	cout << sum;

	return 0;
}

void Union(int a, int b)
{
	int num1 = Find(a);
	int num2 = Find(b);

	if (num1 < num2)
	{
		arr[num2] = num1;
	}
	else
	{
		arr[num1] = num2;
	}
}
int Find(int num)
{
	if (arr[num] == num)
	{
		return num;
	}
	else
	{
		arr[num] = Find(arr[num]);
	}
	return arr[num];
}