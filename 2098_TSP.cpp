#include <cstring>
#include <iostream>

using namespace std;

#define MAX 16
#define INT_MAX 987654321

int N;
int map[MAX][MAX];
int dpCost[MAX][1 << MAX];
// dpCost[i][j] = i 도시 방문, j 도시들[이진표기]을 방문한 상태의 최소 비용

int Dfs(int cur, int visited) {

    // 모든 도시를 방문한 경우
    // (1 << N) - 1 => 11..11 => 모두 방문
    if (visited == ((1 << N) - 1)) {
        if (map[cur][0] == 0)
            return INT_MAX;

        return map[cur][0];
    }

    // 이미 방문한 도시인 경우
    if (dpCost[cur][visited] != -1)
        return dpCost[cur][visited];

    // -1이므로 방문하지 않은 도시인 경우
    dpCost[cur][visited] = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (map[cur][i] == 0)   // 연결 X
            continue;
        if (visited & (1 << i)) // 이미 방문
            continue;
        // 1 << i => i번째 도시 방문 
        // & => 비트 단위 AND 연산
        // visited & (1 << i) => i번째 도시 방문 여부 확인

        dpCost[cur][visited] = min(dpCost[cur][visited], map[cur][i] + Dfs(i, visited | (1 << i)));
    }

    return dpCost[cur][visited];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // input
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }

    // init
    memset(dpCost, -1, sizeof(dpCost));

    // output
    int res = Dfs(0, 1);
    cout << res << '\n';

    return 0;
}