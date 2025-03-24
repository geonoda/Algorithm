#include <iostream>

using namespace std;
int arr[101][21];
int DP[101][21][21];//현재 나무의 i번째 구멍은 이전 나무의 가능한 구멍에 대한 조합이 가능.
int main(void)
{
    int N, T = 0;
    cin >> N >> T;

    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            for (int k = 0; k < 21; k++)
            {
                DP[i][j][k] = 987654321;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        int num = 0;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int k = 0;
            cin >> k;
            arr[i][k] = 1;//1으로 설정되어 있으면 구멍이 있음
        }
    }


   // for (int i = 1; i <= N; i++)
   ///* {
   //     for (int j = 1; j <= 20; j++)
   //     {
   //         cout << arr[i][j] << " ";
   //     }
   //     cout << endl;
   // }*/
    arr[0][1] = 1;
    for (int i = 1; i <= 20; i++)
    {
        if (arr[0][i] == 1)
        {
            for (int j = 1; j <= 20; j++)
            {
                DP[0][i][j] = 0;
            }
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= 20; k++)
        {
            if (arr[i][k] == 1)//i번째 나무에 k높이에 구멍이 있다면??
            {
                int j = i - 1;

                for (int p = 1; p <= 20; p++)//이전 나무도 높이가 20까지 살펴봐야함.
                {
                    if (k == p + 1 && arr[j][p] == 1)
                    {
                        int min = 987654321;
                        int index = -1;
                        for (int b = 1; b <= 20; b++)
                        {
                            if (DP[j][p][b] < min)
                            {
                                min = DP[j][p][b];
                                index = b;
                            }
                        }
                        if (DP[i][k][p] > DP[j][p][index])
                        {
                            DP[i][k][p] = DP[j][p][index];////이전 나무의 p높이 중 최솟값
                        }
                        
                    }
                    else if ((k == p - 1 && arr[j][p] == 1))
                    {
                        int min = 987654321;
                        int index = -1;
                        for (int b = 1; b <= 20; b++)
                        {
                            if (DP[j][p][b] < min)
                            {
                                min = DP[j][p][b];
                                index = b;
                            }
                        }
                        if (DP[i][k][p] > DP[j][p][index])
                        {
                            DP[i][k][p] = DP[j][p][index];////이전 나무의 p높이 중 최솟값
                        }
                    }
                    else if ((k == p && arr[j][p] == 1))
                    {
                        int min = 987654321;
                        int index = -1;
                        for (int b = 1; b <= 20; b++)
                        {
                            if (DP[j][p][b] < min)
                            {
                                min = DP[j][p][b];
                                index = b;
                            }
                        }
                        if (DP[i][k][p] > DP[j][p][index])
                        {
                            DP[i][k][p] = DP[j][p][index];////이전 나무의 p높이 중 최솟값
                        }
                    }
                    else if ((k == p * 2 && arr[j][p] == 1))
                    {
                        int min = 987654321;
                        int index = -1;
                        for (int b = 1; b <= 20; b++)
                        {
                            if (DP[j][p][b] < min)
                            {
                                min = DP[j][p][b];
                                index = b;
                            }
                        }
                        if (DP[i][k][p] > DP[j][p][index])
                        {
                            DP[i][k][p] = DP[j][p][index];////이전 나무의 p높이 중 최솟값
                        }
                    }
                    else if (arr[j][p] == 1)
                    {
                        int min = 987654321;
                        int index = -1;
                        for (int b = 1; b <= 20; b++)
                        {
                            if (DP[j][p][b] < min)
                            {
                                min = DP[j][p][b];
                                index = b;
                            }
                        }
                        if (k == 20&&p>=10)
                        {
                            if (DP[i][k][p] > DP[j][p][index])
                            {
                                DP[i][k][p] = DP[j][p][index];////이전 나무의 p높이 중 최솟값
                            }
                        }
                        else
                        {
                            if (DP[i][k][p] > DP[j][p][index] + 1)
                            {
                                DP[i][k][p] = DP[j][p][index] + 1;////이전 나무의 p높이 중 최솟값
                            }
                        }
                        
                    }

                }
            }
        }
    }

        int result = 987654321;

        //for (int b = 0; b <= N; b++)
        //{
        //    for (int i = 1; i <= 20; i++)
        //    {
        //        if (arr[b][i] == 1)
        //        {
        //            //cout << i;
        //            for (int j = 1; j <= 20; j++)
        //            {
        //                if (result > DP[b][i][j])
        //                {
        //                    result = DP[b][i][j];
        //                }
        //                cout << DP[b][i][j] << " ";
        //            }
        //            cout << endl;
        //        }
        //    }
        //}

        for (int i = 1; i <= 20; i++)
        {
            if (arr[N][i] == 1)
            {
                for (int j = 1; j <= 20; j++)
                {
                    if (result > DP[N][i][j])
                    {
                        result = DP[N][i][j];
                    }
                }
            }
        }

        if (result > T || result==987654321)
        {
            cout << -1;
        }
        else
        {
            cout << result;
        }
        
        return 0;

    }
