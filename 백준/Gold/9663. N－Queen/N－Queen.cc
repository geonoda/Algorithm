#include<iostream>
using namespace std;
int ge(int a, int b);
int n=0;
int m=0;
int result[16]={0};
int num=0;
int main()
{
   ios::sync_with_stdio(false);
  cin.tie(NULL);
 result[0]=0;
    cin>>m;
    
    ge(1,1);
    cout<<num;
    return 0;
}
int ge(int a, int b)
{
    for(int i=1; i<=m; i++)
    {
        if(b<=m)
        {
           result[b]=i;
           int sig=0;
          
                for(int p=1; p<=b-1; p++)
                {
                   if (result[p]==result[b])
                   {
                       sig=1;
                       break;
                   }
                   int t=b-p;
                   int y=result[p]-result[b];
                   if(t<0)
                   {
                       t=-t;
                       
                   }
                   if(y<0)
                   {
                       y=-y;
                   }
                   
                   if(t==y)
                   {
                       sig=1;
                       break;
                   }
                   
                }
               
            
            if(sig!=1)
            {
               ge(a,b+1);
            }
            
        }
        else
        {
            
            for(int l=1; l<=m; l++)
            {
               //cout<<result[l]<<" ";
            }
            //cout<<"\n";
            num++;
            break; 
            
        }
        
    }
    return 0;
}