#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<char>q1;
queue<char>q2;
int main(void)
{
	string s = "";
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a')
		{
			q1.push('a');
		}
		else
		{
			q2.push('b');
		}
	}

	while (!q2.empty())
	{
		q1.push(q2.front());
		q2.pop();
	}

	int min = 987654321;

	for(int k=0; k<s.size(); k++)
	{
		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != q1.front())
			{
				count++;
			}
			q1.push(q1.front());
			q1.pop();
		}
		if (min > count)
		{
			min = count;
		}
		q1.push(q1.front());
		q1.pop();
	}

	cout << min/2;

	return 0;
}