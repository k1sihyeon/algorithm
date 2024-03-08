#include <iostream>
#include <queue>
using namespace std;

int N, K;

bool visited[100001] = { false, };
queue<pair<int, int>> q;
int result = 0;

bool isInside(int x) {
    return ((x >= 0) && (x <= 100000));
}

void bfs(int n) {
    while (!q.empty()) {
        int loc = q.front().first;
        int time = q.front().second;

        q.pop();

        if (loc == K) {
            result = time;
            return;
        }

        if (isInside(loc - 1) && !visited[loc - 1]) {
            q.push(make_pair(loc - 1, time + 1));
            visited[loc - 1] = true;
        }

        if (isInside(loc + 1) && !visited[loc + 1]) {
            q.push(make_pair(loc + 1, time + 1));
            visited[loc + 1] = true;
        }

        if (isInside(loc * 2) && !visited[loc * 2]) {
            q.push(make_pair(loc * 2, time + 1));
            visited[loc * 2] = true;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    q.push(make_pair(N, 0));
    visited[N] = true;

    bfs(N);

    cout << result << '\n';

    return 0;
}