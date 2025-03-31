#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> table(N+1, vector<int>(N+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;

            table[i][j] = table[i-1][j] + table[i][j-1] - table[i-1][j-1] + num;    // 누적 합
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << table[x2][y2] - table[x2][y1-1] - table[x1-1][y2] + table[x1-1][y1-1] << "\n";
    }

    return EXIT_SUCCESS;
}