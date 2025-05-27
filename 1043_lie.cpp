#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> parent;

int Find(int x) {
    if (parent[x] == x)
        return x;

    parent[x] = Find(parent[x]);
    
    return parent[x];
}

void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);

    if (pa != pb)
        parent[pb] = pa;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    int result = 0;

    vector<int> truthKnower;
    vector<vector<int>> party;
    set<int> truthRoot;

    //

    cin >> N >> M;
    cin >> K;

    parent.assign(N+1, 0);
    for (int i = 1; i <= N; i++)
        parent[i] = i;
    
    truthKnower.assign(K, 0);
    for (int i = 0; i < K; i++)
        cin >> truthKnower[i];

    party.resize(M);
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        
        party[i].resize(num);
        for (int j = 0; j < num; j++)
            cin >> party[i][j];

        for (int j = 1; j < num; j++)
            Union(party[i][0], party[i][j]);
    }

    
    for (const int & t : truthKnower)
        truthRoot.insert(Find(t));

    for (const auto & pt : party) {
        bool known = false;

        for(const int & attendee : pt) {
            if (truthRoot.count(Find(attendee))) {
                known = true;
                break;
            }
        }

        if (!known)
            result += 1;
    }

    cout << result << "\n";

    return EXIT_SUCCESS;
}