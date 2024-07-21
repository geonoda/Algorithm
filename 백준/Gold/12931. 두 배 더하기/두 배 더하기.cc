#include <iostream>

using namespace std;
int A[100];
int B[100];
int main(void)
{
	int N=0;
	int count=0;
	int zero=0;
	
	cin>>N;
	
	for(int i=0; i<N; i++)
	{
		cin>>B[i];
		if(B[i]==0)
		{
			zero++;
		}
	}
	
	
	while(true)
	{
		int sig=0;
		
		for(int i=0; i<N; i++)
		{
			if(B[i]%2!=0&&B[i]>0)
			{
				B[i]=B[i]-1;
				count++;
				sig=1;
				
				if(B[i]==0)
				{
					zero++;
				}
			}
		}
		
		if(zero==N)//전부 0이라면?? 종료 
		{
			cout<<count;
			break;
		}
		
		if(sig==0)
		{
			for(int i=0; i<N; i++)
			{
				B[i]=B[i]/2;
			}
			count++;
		}
		
	}
	  
	return 0;
}