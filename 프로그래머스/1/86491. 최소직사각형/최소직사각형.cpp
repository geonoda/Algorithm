#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int Lmax = 0;
    int Rmax = 0;

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
        
        if (sizes[i][0] > Lmax)
        {
            Lmax = sizes[i][0];
        }

        if (sizes[i][1] > Rmax)
        {
            Rmax = sizes[i][1];
        }
    }

    answer = Lmax * Rmax;

    return answer;
}