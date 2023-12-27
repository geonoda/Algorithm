#include<iostream>
using namespace std;

int main()
{
    int a;
    int b;
    
    cin>>a>>b;
    int count=0;
    int count2=0;
    for(int i=1; i<=a; i++)
    {
        if(a%i==0)
        {
            count++;
            if(count==b)
            {
                cout << i << endl;
                count2++;
                break;
            }
            
        }
        
        
    }
    
    if(count2==0)
    {
        cout<<0;
    }
    return 0;
}