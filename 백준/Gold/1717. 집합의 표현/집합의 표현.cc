#include <iostream>
using namespace std;

int parent[1000001];

int find(int a)//재귀적으로 부모를 찾아 들어감 
{
    if(parent[a] == a)
	{
        return a;
    }
    return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
	{
        return;
    }
    parent[b] = a;
}

bool Check(int a, int b)//같은 집합에 존재하는지 확인하는 함수 
{
    a = find(a);
    b = find(b);
    if(a == b)
	{
        return true;
    }
    return false;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1;i<=1000000;i++)
	{
        parent[i] = i;
    }

    int n,m;
    cin>>n>>m;

    for(int i = 0;i<m;i++)
	{
        int sig, num1, num2;
        cin>>sig>>num1>>num2;
        if(sig == 0) 
		{
            Union(num1,num2);
        }
        else if(sig == 1)
		{
            if(Check(num1,num2) == false)//만약 부모가 다르면 NO 
			{
                cout<<"NO"<<'\n';
            }
            else//만약 부모가 같으면 Yes 
			{
                cout<<"YES"<<'\n';
            }
        }
    }

    return 0;
}