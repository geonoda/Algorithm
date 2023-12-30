#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int MAX_SIZE=1000000;
	int a=0;
	int b=0;
	cin>>a>>b;
	int *arr = (int *)malloc(sizeof(int) *MAX_SIZE );
	for (int i = 2; i*i <= b; i++) {
        for (int j = i*i; j <= b; j = j+i) {
            if (arr[j] == 0) {
                arr[j] = 1;
            }
        }
    }
 
    for (int i = a; i <= b; i++) {
    	if(i==1)
    	{
    		
		}
        else if (arr[i] == 0) {
            cout << i << '\n';
        }
    }
     free(arr);
	return 0;
}