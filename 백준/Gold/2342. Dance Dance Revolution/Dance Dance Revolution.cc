#include <iostream>
#include <vector>
using namespace std;
int DP[100001][5][5] = { 0 };
vector<int>v;
int main(void)
{
	v.push_back(0);
	while (true)
	{
		int num = 0;
		cin >> num;
		if (num == 0)
		{
			break;
		}
		else
		{
			v.push_back(num);
		}
	}

	for (int k = 0; k < 100001; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				DP[k][i][j] = 987654321;
			}
		}
	}

	DP[0][0][0] = 0;

	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				int temp = 0;
				if (j == 0)//만약 왼쪽발이 처음 시작한다면?
				{
					temp = 2;
				}

				else
				{
					int num = abs(v[i] - j);
					if (num == 2)
					{
						temp = 4;
					}
					else if (num == 0)
					{
						temp = 1;
					}
					else
					{
						temp = 3;
					}
				}
				
			

				if (DP[i][v[i]][k] > DP[i - 1][j][k]+temp) //DP[i][v[i]][j];//오른발이 v[i]를 밟는다면?
				{
					DP[i][v[i]][k] = DP[i - 1][j][k] + temp;
					if (v[i] == 2 && k == 0)
					{
						//cout << DP[i][v[i]][k] << " "<<temp;
					}
				}

				int temp2 = 0;
				if (k == 0)//만약 왼쪽발이 처음 시작한다면?
				{
					temp2 = 2;
				}
				else
				{
					if (abs(v[i] - k) == 2)
					{
						temp2 = 4;
					}
					else if (abs(v[i] - k) == 0)
					{
						temp2 = 1;
					}
					else
					{
						temp2 = 3;
					}
				}
				
				if (DP[i][j][v[i]] > DP[i - 1][j][k] + temp2) //DP[i][v[i]][j];//오른발이 v[i]를 밟는다면?
				{
					DP[i][j][v[i]] = DP[i - 1][j][k] + temp2;
				}
			}
		}
	}

	int min = 987654321;
	for (int m = 0; m < v.size(); m++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//cout << DP[m][i][j] << " ";
				if (min > DP[v.size() - 1][i][j])
				{
					min = DP[v.size() - 1][i][j];
				}
			}
			//cout << endl;
		}
		//cout << endl;
	}
	
	cout << min;
	return 0;
}
//만약 이전에 1 2 를 밟고 있는데 3이 들어오면?? 1이 3이 되거나 2가 3이 되어야한다,.
