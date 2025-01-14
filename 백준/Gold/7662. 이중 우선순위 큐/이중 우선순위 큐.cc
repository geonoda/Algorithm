#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visited[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 0;
	cin >> T;
	for (int j = 0; j < T; j++)
	{
		int k = 0;
		cin >> k;

		priority_queue<pair<int,int>> pq1;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
		fill(visited, visited + 1000001, 0); // visited 초기화
		for (int i = 0; i < k; i++)
		{
			char op;
			int num;
			cin >> op >> num;

			if (op == 'I') { // 삽입 연산
				pq1.push({ num, i });
				pq2.push({ num, i });
				visited[i] = 1; // 삽입된 상태로 표시
			}
			else if (op == 'D') { // 삭제 연산
				if (num == 1) { // 최댓값 삭제
					while (!pq1.empty() && !visited[pq1.top().second]) {
						pq1.pop(); // 이미 삭제된 값 정리
					}
					if (!pq1.empty()) {
						visited[pq1.top().second] = 0; // 최댓값 삭제
						pq1.pop();
					}
				}
				else if (num == -1) { // 최솟값 삭제
					while (!pq2.empty() && !visited[pq2.top().second]) {
						pq2.pop(); // 이미 삭제된 값 정리
					}
					if (!pq2.empty()) {
						visited[pq2.top().second] = 0; // 최솟값 삭제
						pq2.pop();
					}
				}
			}
			
		}
		// 최종 출력 전에 큐 정리
		while (!pq1.empty() && !visited[pq1.top().second]) {
			pq1.pop();
		}
		while (!pq2.empty() && !visited[pq2.top().second]) {
			pq2.pop();
		}

		// 결과 출력
		if (pq1.empty() || pq2.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << pq1.top().first << " " << pq2.top().first << "\n";
		}
	}
	return 0;
} //100 -100 -200  앞에서 빼고 뺴고 뒤에서 -50이 들어간 후 뺴고 뺴면? -100이 사라져있어야하는데 왜 있지?