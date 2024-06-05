#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int map[100001];
bool visited[100001];
bool finished[100001];
int result;

void DFS(int cur);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    // test case
    for (int i = 0; i < T; i++) {
        // init
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        result = 0;

        // input
        int n;
        cin >> n;

        for (int j = 1; j <= n; j++) {
            cin >> map[j];
        }

        // DFS
        for (int j = 1; j <= n; j++) {
            if (!visited[j])
                DFS(j);
        }

        // output
        cout << n - result << '\n';
    }

    return 0;
}

void DFS(int cur) {
    visited[cur] = true;
    int next = map[cur];

    if (!visited[next]) {
        DFS(next);
    }
    else {  // 재방문 -> cycle
        if (!finished[next]) {
            for (int i = next; i != cur; i = map[i]) {
                result += 1;
            }
            result += 1;    //wildcard도 여기서 처리됨
        }
    }

    finished[cur] = true;
}