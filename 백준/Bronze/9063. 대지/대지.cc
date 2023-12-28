#include <iostream>

using namespace std;

int main(void)
{
	int a=0;
	int b[100000]={0};
	int c[100000]={0};
	
	cin>>a;
	for(int i=0; i<a; i++)
	{
		cin>>b[i];
		cin>>c[i];
	}
	
	int minx=1000000;
	int maxx=-1000000;
	int miny=1000000;
	int maxy=-1000000;
	for(int i=0; i<a; i++)
	{
		if(minx>b[i])
		{
			minx=b[i];
		}
		if(maxx<b[i])
		{
			maxx=b[i];
		}
		if(miny>c[i])
		{
			miny=c[i];
		}
		if(maxy<c[i])
		{
			maxy=c[i];
		}
	}
	cout<<(maxx-minx)*(maxy-miny);
	return 0;
}