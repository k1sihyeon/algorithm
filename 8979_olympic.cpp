#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

class Country {
    public:
        int country;
        int gold;
        int silver;
        int bronze;
        int rank;
};

vector<Country> v;

void SetRank() {
    for (int i = 0; i < N; i++) {
        if (i == 0) 
            v[i].rank = 1;
        else {
            if (v[i].gold == v[i - 1].gold && v[i].silver == v[i - 1].silver && v[i].bronze == v[i - 1].bronze) {
                v[i].rank = v[i - 1].rank;
            }
            else
                v[i].rank = i + 1;
        }
    }
}

bool cmp(Country a, Country b) {
    if (a.gold != b.gold) 
        return a.gold > b.gold;

    if (a.silver != b.silver) 
        return a.silver > b.silver;

    if (a.bronze != b.bronze) 
        return a.bronze > b.bronze;

    return a.country == K;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        Country c;
        cin >> c.country >> c.gold >> c.silver >> c.bronze;
        v.push_back(c);
    }

    sort(v.begin(), v.end(), cmp);

    SetRank();

    for (int i = 0; i < N; i++) {
        if (v[i].country == K) {
            cout << v[i].rank << '\n';
            break;
        }
    }

    return 0;
}