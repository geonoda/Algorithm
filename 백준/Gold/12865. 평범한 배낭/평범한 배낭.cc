#include <iostream>

using namespace std;

int DP[100001];

int main(void)
{
	int n=0;
	int k=0;
	
	cin>>n>>k;
	
	for(int i=1; i<=n; i++)
	{
		int w=0;
		int v=0;
		cin>>w>>v;
		int temp[100001]={0};
		for(int j=1; j<=k; j++)
		{
			if(j-w>=0&&temp[j-1]<DP[j-w]+v)
			{
				temp[j]=DP[j-w]+v;
			}
			else
			{
				temp[j]=temp[j-1];
			}
			if(DP[j]>temp[j])
			{
				temp[j]=DP[j];
			}
		}
		
		for(int i=1; i<=k; i++)
		{
			DP[i]=temp[i];
		}
		
	}
	
	
	cout<<DP[k];
	
	return 0;
}