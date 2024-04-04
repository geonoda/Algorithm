#include <iostream> 

using namespace std;

int re(int k,int x, int y);
int a=0;
char arr[3][3]={{'*','*','*'},{'*',' ','*'},{'*','*','*'}};
int main(void)
{
	cin>>a;
	
	re(a,0,0);
			
	return 0;
}
int re(int k,int x, int y)
{
	if(k==1)
	{
		cout<<arr[x][y];
	}
	else if(k==a)
	{
		for(int i=0; i<k; i++)
		{
			for(int j=0; j<k; j++)
			{
				if(i>=k/3&&j>=k/3&&i<2*k/3&&j<2*k/3)
				{
					cout<<" ";
				}
				else
				{
					re(k/3,i,j);	
				}
				
			}
			cout<<endl;
		}
	}
	else
	{
		if(x%k>=k/3&&y%k>=k/3&&x%k<2*k/3&&y%k<2*k/3)
		{
			cout<<" ";
		}
		else
		{
			re(k/3,x%k,y%k);
		}
		
	}
	return 0;
}