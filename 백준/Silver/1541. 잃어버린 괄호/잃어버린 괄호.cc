#include <iostream>
#include <string>

using namespace std;

int main(void)
{
   string a="";
   cin>>a;
   
   int sum=0;
   string temp="";
   int sig=0;
   int tempsum=0;
   int first=0;
   for(int i=0; i<=a.length(); i++)
   {
      if(a[i]=='+')
      {
         if(first==0)
         {
            sum=sum+stoi(temp);
            first=1;
            temp="";
         }
         int j=i+1;
         while(true)
         {
   
            if(a[j]=='-'||a[j]=='\0')
            {
               i=j-1;
               break;   
            }
            
            if(a[j]=='+')
            {
               sum=sum+stoi(temp);
               temp="";
               j++;
            }
            else
            {
               temp=temp+a[j];
               j++;
            }
         }
         sum=sum+stoi(temp);
         temp="";
      }
      else if(a[i]=='-')
      {
         int j=i+1;
         if(first==0)
         {
            sum=sum+stoi(temp);
            first=1;
            temp="";
         }
         int sig=0;
         while(true)
         {
   
            if(a[j]=='-'||a[j]=='\0')
            {
               i=j-1;
               break;   
            }
            
            if(a[j]=='+')
            {
               sum=sum-stoi(temp);
               temp="";
               j++;
            }
            else
            {
               temp=temp+a[j];
               j++;
            }
         }
         
         sum=sum-stoi(temp);
         temp="";
         
         
      }
      else
      {
         temp=temp+a[i];
      }
      
   }
  if(first==0)
      {
         sum=sum+stoi(temp);
      }
   cout<<sum;
   
   return 0;
}