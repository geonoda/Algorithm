#include <iostream>
#include <algorithm>

using namespace std;

int arr[300001];
int gap[300001];

int main(void)
{
	int N=0;
	int K=0;
	
	cin>>N>>K;
	
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
	}
	
	sort(arr,arr+N);
	
	int sum=0;
	
	for(int i=0; i<N-1; i++)
	{
		gap[i]=arr[i+1]-arr[i];
		sum+=gap[i];
	}
	
	
	sort(gap,gap+(N-1));
	
	for(int i=0; i<K-1; i++)
	{
		sum-=gap[N-2-i];
	}
	
	cout<<sum;
	

	return 0;
}