#include <iostream>
#include <unordered_map>
#include<string>

using namespace std;

int main(void)
{
	int a=0;
	cin>>a;
	unordered_map<string, int> wordMap;
	wordMap["ChongChong"]=1;
	int count=1;
	for(int i=0; i<a; i++)
	{
		string a=" ";
		string b=" ";
		
		cin>>a>>b;
		
		auto it = wordMap.find(a);
		auto it2 = wordMap.find(b);
		
		if (it == wordMap.end())
		{
			if(it2 != wordMap.end())
			{
				if(it2->second==1)
				{
					
					count++;
					wordMap[a]=1;
					
				}
			}
			
		}
		
		if (it2 == wordMap.end())
		{
			if(it != wordMap.end())
			{
				if(it->second==1)
				{
					count++;
					wordMap[b]=1;
				}
			}
			
		}
		
		
	}
	cout<<count;
	return 0;
}