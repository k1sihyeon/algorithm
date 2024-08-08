#include <bits/stdc++.h>

using namespace std;

#define INF 97654321

int N, M, R;

int ground[101][101];

vector<int> item;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> M >> R;

    // init
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            ground[i][j] = INF;
        }
    }

    item.push_back(0);  // idx 맞추기
    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
        item.push_back(T);
    }

    for (int i = 0; i < R; i++) {
        int from, to, dist;
        cin >> from >> to >> dist;

        ground[from][to] = dist;
        ground[to][from] = dist;
    }
    // 1. 모든 정점간 거리 계산
    // 2. 한계 거리내의 얻을 수 있는 아이템 계산

    // 플로이드 와셜 - 모든 정점간 거리
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                ground[i][j] = min(ground[i][j], ground[i][k] + ground[k][j]);

    for (int i = 1; i <= N; i++) {
        ground[i][i] = 0;
    }

    int ans = -1;

    for (int i = 1; i <= N; i++) {
        int maxItem = 0;
        for (int j = 1; j <= N; j++) {
            if ((ground[i][j] <= M)) {
                maxItem += item[j];
            }
        }
        ans = max(maxItem, ans);
    }

    cout << ans << "\n";

    return 0;
}