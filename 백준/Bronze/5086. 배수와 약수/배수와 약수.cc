#include<iostream>
using namespace std;

int main()
{
    int num1=0;
    int num2=0;
    
    int a[10000];
    int i=0;
    while(true)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            break;
        }
        i++;
        
    }
    int j=0;
    while(true){
    		
	    if(a[j]==0)
	    {
	        break;
	    }
        
        num2=a[j+1];
        num1=a[j];
    
	    if(num2%num1==0)
	    {
	        cout << "factor" << endl;
	    }
	    else if(num1%num2==0)
	    {
	       cout << "multiple" << endl;
	    }
	    else
	    {
	        if(num1==0||num2==0)
	        {
	        }
	        else
	        {
	           cout << "neither" << endl;
	        }
	       
	    }
	    j=j+2;
    }
    
    return 0;
}