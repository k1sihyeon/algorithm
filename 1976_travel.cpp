#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edges;
//vector<vector<int>> graph;
vector<int> plan;
int parent[201];

int Find(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a < b)
        parent[b] = a;
    else 
        parent[a] = b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if (i < j && num != 0)
                edges.push_back({num, {i + 1, j + 1}});
        }
    }

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        plan.push_back(num);
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= N; i++)
        parent[i] = i;
    
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int from = edges[i].second.first;
        int to = edges[i].second.second;

        if (Find(from) != Find(to)) {
            Union(from, to);
        }
    }

    bool flag = true;
    for (int i = 0; i < M - 1; i++) {
        if (Find(plan[i]) != Find(plan[i + 1])) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';


    return 0;
}