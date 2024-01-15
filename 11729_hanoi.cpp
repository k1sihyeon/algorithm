#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

void hanoi(int n, int from, int now, int to) {
    
    if (n == 1) {
        v.push_back(make_pair(from, to));
        return;
    }

    hanoi(n - 1, from, to, now);
    v.push_back(make_pair(from, to));
    hanoi(n - 1, now, from, to);
}

int main(void) {
    
    int N;
    cin >> N;

    hanoi(N, 1, 2, 3);

    cout << v.size() << "\n";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}