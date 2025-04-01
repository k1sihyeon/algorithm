#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        int cnt = 1;
        int next = 0;

        vector<pair<int, int>> grades;

        cin >> N;

        for (int i = 0; i < N; i++) {
            int paper, interview;
            cin >> paper >> interview;
            grades.push_back({paper, interview});
        }

        sort(grades.begin(), grades.end());

        for (int i = 1; i < N; i++) {
            if (grades[next].second > grades[i].second) {
                cnt += 1;
                next = i;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}