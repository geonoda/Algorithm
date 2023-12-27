#include<iostream>
using namespace std;

int main()
{
    int a=0;
    cin>>a;
    int sum=a;
    int count=0;
    int k[100000]={0};
    for(int i=2; i<=a; i++)
    {
        if(a%i==0)
        {
            a=a/i;
            k[count]=i;
            count++;
            i--;
        }
        if(a==0)
        {
            break;
        }
    }
    for(int i=0; i<count; i++)
    {
        cout<<k[i]<<endl;
    }
    
    return 0;
}