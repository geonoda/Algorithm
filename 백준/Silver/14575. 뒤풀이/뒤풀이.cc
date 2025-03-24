#include <iostream>

using namespace std;
int arr1[1001];
int arr2[1001];
int main(void)
{
	int N, T = 0;
	cin >> N >> T;

	int Lall = 0;
	int Rall = 0;
	int Lmax = 0;
	int Rmax = 0;
	for (int i = 0; i < N; i++)
	{
		int L, R = 0;
		cin >> L >> R;
		arr1[i] = L;
		arr2[i] = R;
		Lall += L;
		Rall += R;
		if (L > Lmax)
		{
			Lmax = L;
		}
		if (R > Rmax)
		{
			Rmax = R;
		}
	}
	//cout << Lall << " " << Rall << endl;

	if (T >= Lall && T <= Rall)
	{
		while (Lmax <= Rmax)
		{
			int mid = (Lmax + Rmax) / 2;

			int Lsum = 0;
			int Rsum = 0;
			for (int i = 0; i < N; i++)
			{
				Lsum += arr1[i];
				if (arr2[i] < mid)
				{
					Rsum += arr2[i];
				}
				else
				{
					Rsum += mid;
				}
			}
			if (T >= Lsum && T <= Rsum)
			{
				Rmax = mid - 1;
			}
			else
			{
				Lmax = mid + 1;
			}
		}
		cout << Lmax;
	}
	
	else
	{
		cout << -1;
	}



	//왼쪽에서 제일 큰 값 오른쪽에서 제일 작은 값
	//예제에서는 4 이상 // 3 이하 (일단 항상 4이상이 되어야한다.)
	//입력은 1부터 100만까지 가능해보임
	//4부터 하나씩 차근차근 검사해보자 10까지
	//4부터 10까지 LR을 두고 검사를 한다?
	//아니 일단 4부터 10까지 계산하면 됨/
	//예를 들어 4가 들어오면 첫번째는 2~4까지 가능해지고 두번째는 4~4까지 가능해짐 세번째는 1~3까지 가능해진다 이걸 이용하자. 최소7부터 최대 11까지 가능해짐
	//
	return 0;
}
