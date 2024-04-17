#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> parent(10001, 0);
vector<bool> visited(10001, false);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        //init
        fill(parent.begin(), parent.end(), 0);
        fill(visited.begin(), visited.end(), false);

        for (int j = 1; j <= N; j++) {
            parent[j] = j;
        }

        //input
        for (int j = 0; j < N - 1; j++) {
            int a, b;
            cin >> a >> b;

            parent[b] = a;
        }

        int s, e;
        cin >> s >> e;
        
        //LCA 찾기

        //DFS - s
        visited[s] = true;
        while (s != parent[s]) {    //부모가 자기 자신이면 루트
            s = parent[s];
            visited[s] = true;
        }

        //DFS - e
        while (true) {    
            if (visited[e]) {
                cout << e << "\n";
                break;
            }

            e = parent[e];
        }
       
    }

    return 0;
}