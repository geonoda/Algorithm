#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string c1;
	string c2;
	
	cin>>c1>>c2;
	
	int num1=0;
	int num2=0;
	
	for(int i=0; i<c1.size(); i++)
	{
		if(c1[i]=='A')
		{
			num1++;
		}
		else if(c1[i]=='B')
		{
			num2++;
		}
	}
	
	int num3=0;
	int num4=0;
	
	for(int i=0; i<c2.size(); i++)
	{
		if(c2[i]=='A')
		{
			num3++;
		}
		else if(c2[i]=='B')
		{
			num4++;
		}
	}
	
	if(num1>num3||num2>num4)
	{
		cout<<0;
		return 0;
	}
	
	int A=num3-num1;
	int B=num4-num2;
	
	int start=0;
	int end=c2.size()-1;
	int dir=1;
	while(true)
	{
		if(c2[end]=='A')
		{
			A--;
			if(dir==1)
			{
				end--;
			}
			else
			{
				end++;
			}
			
		}
		else if(c2[end]=='B')
		{
			B--;
			int temp=start;
			
			start=end-dir;
			end=temp;
			dir=(dir*(-1));
		}
		
		
		if(A<0||B<0)
		{
			cout<<0;
			break;
		}
		else if(A==0&&B==0)
		{
			int sig=0;
			int dir=1;
			if(start>end)
			{
				dir=-1;	
			}

			for(int i=0; i<c1.size(); i++)
			{
				if(c2[start]!=c1[i])
				{
					sig=1;
					break;
				}
				start=start+dir;
			}
			if(sig==0)
			{
				cout<<1;	
			}
			else
			{
				cout<<0;
			}
			
			break;
		}
		
	}
	
	return 0;
}