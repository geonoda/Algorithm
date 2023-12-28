#include <iostream>

using namespace std;

int main(void)
{
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int e=0;
	int f=0;
	int g=0;
	int h=0;
	cin>>a>>b>>c>>d>>e>>f;
	
	if(a==c)
	{
		g=e;
	}
	else if(a==e)
	{
		g=c;
	}
	else if(c==e)
	{
		g=a;
	}
	
	if(b==d)
	{
		h=f;
	}
	else if(b==f)
	{
		h=d;
	}
	else if(d==f)
	{
		h=b;
	}
	
	cout<<g<<" "<<h;
	return 0;
}