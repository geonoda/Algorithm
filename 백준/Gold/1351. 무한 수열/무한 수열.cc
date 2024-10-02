#include <iostream>
#include <unordered_map>

using namespace std;

long long sol(long long num);

unordered_map<long long, long long> hashMap;
long long N, P, Q = 0;
int main(void)
{
	cin >> N >> P >> Q;
	hashMap[0] = 1;
	if (N == 0)
	{
		cout << 1;
	}
	else
	{
		cout << sol(N / P) + sol(N / Q);
	}
	
	return 0;
}

long long sol(long long num)
{
	long long result = 0;
	if (hashMap.find(num) != hashMap.end())//hashMap에 찾고자하는 값이 있다면 return한다.
	{
		return hashMap[num];
	}
	result = sol(num / P) + sol(num/Q);//찾고자하는 값이 없다면 값을 구한다.
	hashMap[num] = result;
	return result;
}