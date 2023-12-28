#include<iostream>
using namespace std;

int main()
{
    int a=0;
    
    cin>>a;
    
    int k=1000000;
    int count=7;
    while(true)
    {
        int m=a/k;
        
        if(m>0)
        {
            break;
        }
        k=k/10;
        count--;
    }
    
    
    int sum=0;
    int m=k;
    int result=10000000;
    int c;
    int v;
    for(int i=a-1; i>a-100; i--)
    {
        sum=sum+i;
        int tmep=i;
        for(int l=0; l<count; l++)
        {
            c=tmep/m;
            tmep=tmep%m;
           sum=sum+c;
           m=m/10;
           
        }
        if(sum==a&&result>i)
        {
            result=i;
        }
        sum=0;
        m=k;
        
    }
    if(result==10000000)
    {
       cout<<0;
    }
    else
    {
       cout<<result;
    }
        
     
     
    return 0;
}