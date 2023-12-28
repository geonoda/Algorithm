#include<iostream>
#include<string>
using namespace std;

int main()
{
    int a=0;
    cin>>a;
    int count=0;
    int count2=0;
    for(int i=0; i<1000000000; i++)
    {
        string k=to_string(i);

        for(int j=0; j<k.length(); j++)
        {
            if(k[j]=='6')
            {
                count++;
            }
            else
            {
                count=0;
            }
            if(count==3)
            {
                count2++;
                break;
            }
        }
        if(count2==a)
        {
            cout<<k;
            break;
        }
        count=0;
    }
    return 0;
}