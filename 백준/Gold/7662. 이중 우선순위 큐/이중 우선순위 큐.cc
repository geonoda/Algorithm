#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        priority_queue<pair<int, int>> max_pq; // 최댓값 우선순위 큐
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq; // 최솟값 우선순위 큐
        fill(visited, visited + 1000001, 0); // visited 초기화

        for (int i = 0; i < k; i++) {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I') { // 삽입 연산
                max_pq.push({num, i});
                min_pq.push({num, i});
                visited[i] = 1; // 삽입된 상태로 표시
            } else if (op == 'D') { // 삭제 연산
                if (num == 1) { // 최댓값 삭제
                    while (!max_pq.empty() && !visited[max_pq.top().second]) {
                        max_pq.pop(); // 이미 삭제된 값 정리
                    }
                    if (!max_pq.empty()) {
                        visited[max_pq.top().second] = 0; // 최댓값 삭제
                        max_pq.pop();
                    }
                } else if (num == -1) { // 최솟값 삭제
                    while (!min_pq.empty() && !visited[min_pq.top().second]) {
                        min_pq.pop(); // 이미 삭제된 값 정리
                    }
                    if (!min_pq.empty()) {
                        visited[min_pq.top().second] = 0; // 최솟값 삭제
                        min_pq.pop();
                    }
                }
            }
        }

        // 최종 출력 전에 큐 정리
        while (!max_pq.empty() && !visited[max_pq.top().second]) {
            max_pq.pop();
        }
        while (!min_pq.empty() && !visited[min_pq.top().second]) {
            min_pq.pop();
        }

        // 결과 출력
        if (max_pq.empty() || min_pq.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_pq.top().first << " " << min_pq.top().first << "\n";
        }
    }

    return 0;
}
