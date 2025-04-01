#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
int minTime = 100001;

vector<bool> visited(100001, false);

bool isInside(int x) {
    return ((x >= 0) && (x <= 100000));
}

void BFS(int n) {
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;

    while (!q.empty()) {
        int loc = q.front().first;
        int time = q.front().second;
        q.pop();

        visited[loc] = true;

        if (loc == K) { 
            if (time < minTime) {   // 최소시간으로 갱신되는 방문
                minTime = time;
            }
        }
        else if (time > minTime) {  // 최소 시간 보다 넘은 시간
            continue;
        }
        else {
            if (isInside(loc - 1) && !visited[loc - 1]) {
                q.push({loc - 1, time + 1});
            }
    
            if (isInside(loc + 1) && !visited[loc + 1]) {
                q.push({loc + 1, time + 1});
            }
    
            if (isInside(loc * 2) && !visited[loc * 2]) {
                q.push({loc * 2, time});
            }
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    BFS(N);

    cout << minTime << "\n";

    return EXIT_SUCCESS;
}