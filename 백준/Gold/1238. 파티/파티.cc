#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int arr[1001][1001];

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = INF;
            }

        }
    }
    for (int i = 1; i <= N; i++) {
        arr[i][i] = 0; // 대각선 값은 0
    }

    for (int i = 0; i < M; i++) {
        int num1, num2, distance;
        cin >> num1 >> num2 >> distance;
        arr[num1][num2] = min(arr[num1][num2], distance); // 간선 중 최소값만 저장
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            if (arr[i][k] == INF) continue; // i에서 k로 갈 수 없는 경우 건너뜀
            for (int j = 1; j <= N; j++) {
                if (arr[k][j] == INF) continue; // k에서 j로 갈 수 없는 경우 건너뜀
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    // 최대 왕복 거리 계산
    int max_dist = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i][X] != INF && arr[X][i] != INF) { // 유효한 경로만 계산
            max_dist = max(max_dist, arr[i][X] + arr[X][i]);
        }
    }

    cout << max_dist << endl;
    return 0;
}
