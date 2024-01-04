#include<iostream>
#include <unordered_map>
#include<string>
using namespace std;

int main()
{
    int a=0;
    cin>>a;
    int sum=0;
    int sig=0;
    unordered_map<string, int> wordMap;
    string k[100001]={" "};
    int n=0;
    int count=0;
    for(int i=0; i<a; i++)
    {
        string t=" ";
        cin>>t;
        
       if(t=="ENTER")
        {
            count++;
        }
        
       auto it = wordMap.find(t);
       if (it != wordMap.end())
       {
          if(t!="ENTER"&&it->second!=count)
           {
              wordMap[t]=count;
               n++;
           }
       }
       else
       {
          if(t!="ENTER")
          {
             wordMap[t]=count;
             n++;
          }
           
       }
    }
    cout<<n;
    return 0;
}