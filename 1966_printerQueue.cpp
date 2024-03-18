#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        priority_queue<int> pq;
        queue<int> q;
        int N, M, cnt = 0;
        cin >> N >> M;
        int idx = M;

        for (int j = 0; j < N; j++) {
            int priority;
            cin >> priority;

            pq.push(priority);
            q.push(priority);
        }

        while (!q.empty()) {
            if (pq.top() == q.front()) {
                pq.pop();
                q.pop();
                cnt += 1;

                if (idx == 0) {
                    cout << cnt << "\n";
                    break;
                }
                else
                    idx -= 1;
            }
            else {
                int tmp = q.front();
                q.pop();
                q.push(tmp);

                if (idx == 0)
                    idx = q.size() - 1;
                else
                    idx -= 1;
            }

        }

    }

    return 0;
}