#include <iostream>
using namespace std;

int main()
{
    int a[100000]={0};
    int i=0;
    
    while(true)
    {
    	
        cin>>a[i];
        if(a[i]==-1)
        {
            break;
        }
        i++;
    }
    int sum=0;
    for(int j=0; j<i; j++)
    {
        int b[100000]={0};
        int count=0;
      
        for(int k=1; k<a[j]; k++)
        {
        	 
            if(a[j]%k==0)
            {
                b[count]=k;
                count++;
                sum=sum+k;
            }
        }
        
        if(sum==a[j])
        {
        	cout<<a[j]<<" = ";
           for(int l=0; l<count; l++)
           {
               if(l!=count-1)
               {
                  cout<<b[l]<<" + ";
               }
               else
               {
                   cout<<b[l]<<endl;
                   
               }
               
           }
        }
        else
        {
            cout<<a[j]<< " is NOT perfect." << endl;
        }
        sum=0;
    }
    return 0;
}