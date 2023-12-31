#include<iostream>
using namespace std;

int main(void){
    int a,b,c,d,e,f=0;
    
    int y;
    int x;
    
    cin>>a>>b>>c>>d>>e>>f;
    
    if(b*d-e*a!=0)
    {
    	y=(c*d-f*a)/(b*d-e*a);
    	
    	if(a!=0)
    	{
    		x=(c-b*y)/a;
		}
		else
		{
			x=(f-e*y)/d;
		}
	    
	    cout<<x<<" "<<y;
	}
    else
    {
    	cout<<0<<" "<<0;
	}
    
    return 0;
}