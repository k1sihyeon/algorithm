#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1000000000

int N, M;
int map[101][101] = {INF, };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    //map INF 초기화, 자기 자신 0 초기화
    //memset(map, INF, sizeof(map));
    fill(&map[0][0], &map[101][101] + 1, INF);
    
    for (int i = 1; i <= N; i++) 
        map[i][i] = 0;

    //입력
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        map[a][b] = min(map[a][b], c);
        //입력되는 간선은 여러개 일 수 있음
    }

    //floyd warshall
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

    //출력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == INF)
                cout << 0 << " ";
            else
                cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}