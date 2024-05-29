#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//kruskal algorithm

int V, E, result = 0;
vector<pair<int, pair<int, int>>> edges;    //cost, from, to //L
//vector<pair<int, pair<int, int>>> mst;      //cost, from, to //T
int parent[10001];

int Find(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b)
        parent[b] = a;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());
    for (int i = 1; i <= V; i++)
        parent[i] = i;
    
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int from = edges[i].second.first;
        int to = edges[i].second.second;

        if (Find(from) != Find(to)) {   //cycle이 발생하지 않는 경우
            Union(from, to);            //from과 to를 연결
            //mst.push_back({cost, {from, to}});  //mst에 추가
            result += cost;
        }
    }

    cout << result << '\n';

    return 0;
}