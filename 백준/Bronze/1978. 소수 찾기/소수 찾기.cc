#include<iostream>
using namespace std;

int main()
{
    int a;
    int b[10000];
    int count=0;
    int count2=0;
    cin>>a;
    for(int i=0; i<a; i++)
    {
        cin>>b[i];
    }
    
    for(int i=0; i<a; i++)
    {
        for(int j=1; j<=b[i]; j++)
        {
            if(b[i]%j==0)
            {
                count++;
            }
        }
        if(count==2)
        {
            count2++;
        }
        count=0;
    }
    cout<<count2;
    
    return 0;
}