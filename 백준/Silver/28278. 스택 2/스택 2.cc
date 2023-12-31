#include <iostream>
#include <stdlib.h>
using namespace std;
int arr[1000001]={0};
int result[1000001]={0};
int main(void)
{
	int count=0;
	int a=0;
	cin>>a;
	int recount=0;
	for(int i=0; i<a; i++)
	{
		int sig=0;
		cin>>sig;
		if(sig==1)
		{
			int num=0;
			cin>>num;
			
			arr[count]=num;
			count++;
		}
		if(sig==2)
		{
			if(count==0)
			{
				//cout<<-1<<'\n';
				result[recount]=-1;
				recount++;
			}
			else
			{
				count--;
				result[recount]=arr[count];
				recount++;
				arr[count]=0;
				//cout<<arr[count]<<'\n';
				
			}
		}
		if(sig==3)
		{
			//cout<<count<<'\n';
			result[recount]=count;
			recount++;
		}
		if(sig==4)
		{
			if(arr[0]==0)
			{
				//cout<<1<<'\n';
				result[recount]=1;
				recount++;
			}
			else
			{
				//cout<<0<<'\n';
				result[recount]=0;
				recount++;
			}
		}
		if(sig==5)
		{
			if(count==0)
			{
				//cout<<-1<<'\n';
				result[recount]=-1;
				recount++;
			}
			else
			{
				//cout<<arr[count]<<'\n';
				result[recount]=arr[count-1];
				recount++;
				
			}
		}
	}
	for(int i=0; i<recount; i++)
	{
		cout<<result[i]<<'\n';
	}
	return 0;
}