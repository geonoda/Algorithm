#include <iostream>

using namespace std;

int main(void)
{
	//1, 2~	3, 4~6, 7~10, 11~15
	
	int count=0;
	
	int num;
	
	cin>>num;
	
	int k=1;
	while(k<=num)
	{
		k=k+count;
		count++;
	}
	count--;
	k=k-count;
	//cout<<k<<endl;
	//cout<<count<<endl;;
	
	if(count%2==0)
	{
		int a=1;
		int b=count;
		int m;
		for(int i=0; i<num-k; i++)
		{
			a=a+1;
			b=b-1;
			m++;
		}
			
		cout<<a<<"/"<<b;
	}
	else if(count%2!=0)
	{
		int a=1;
		int b=count;
		int m;
		for(int i=0; i<num-k; i++)
		{
			a=a+1;
			b=b-1;
			m++;
		}
			
		cout<<b<<"/"<<a;
	}
	return 0;
}

