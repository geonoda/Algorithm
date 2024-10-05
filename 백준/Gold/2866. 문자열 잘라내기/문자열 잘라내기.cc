#include <iostream>
#include <unordered_set>
using namespace std;
string s[1001];
int main(void)
{
	int R, C = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		char temp = ' ';
		for (int j = 0; j < C; j++)
		{
			cin >> temp;
			s[j] = s[j]+ temp;
		}	
	}
	int count = 0;
	

	for (int i = 1; i < C; i++)
	{
		unordered_set<string> hashSet;
		for (int j = 0; j < C; j++)
		{
			string temp = "";
			
			temp=s[j].substr(i, R);
			//cout << temp<<"\n";
			if (hashSet.find(temp) == hashSet.end())
			{
				hashSet.insert(temp);
			}
			else
			{
				cout << count;
				return 0;
			}
		}
		count++;
	}
	return 0;
}