#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10001000;
int earth[101][101] = {MAX, };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, ans;
    cin >> N >> M;

    // memset(earth, MAX, sizeof(earth));
    fill(&earth[0][0], &earth[100][101], MAX);

    // 같은 번호 제거
    for (int i = 1; i <= N; i++)
        earth[i][i] = 0;

    // input
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        earth[a][b] = 1;
        earth[b][a] = 1;
    }

    // floyd warshall
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                earth[i][j] = min(earth[i][j], earth[i][k] + earth[k][j]);


    int minKevin = MAX;

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += earth[i][j];
        }

        if (sum < minKevin) {
            ans = i;
            minKevin = sum;
        }
    }

    cout << ans << "\n";
    
    return EXIT_SUCCESS;
}