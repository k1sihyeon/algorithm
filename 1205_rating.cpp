#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, score, P;
    vector<int> rank;

    cin >> N >> score >> P;

    if (N == 0) {
        cout << 1 << "\n";
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        rank.push_back(num);
    }

    sort(rank.begin(), rank.end(), greater<>());

    if ((N == P) && (score <= rank.back())) {
        cout << -1 << "\n";
        return EXIT_SUCCESS;
    }

    rank.push_back(score);
    sort(rank.begin(), rank.end(), greater<>());

    int result = 0;
    for (int i = 0; i <= (int)rank.size(); i++) {
        if (rank[i] == score) {
            result = i;
            break;
        }
    }

    cout << result + 1 <<"\n";

    return EXIT_SUCCESS;
}