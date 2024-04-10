#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INT_MAX 2147483647

int getDist(string a, string b) {
    int dist = 0;

    for (int i = 0; i < 4; i++)
        if (a[i] != b[i])
            dist += 1;

    return dist;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;

    cin >> T;

    for (int i = 0; i < T; i++) {
        vector<string> v;
        
        cin >> N;

        for (int j = 0; j < N; j++) {
            string str;
            cin >> str;
            v.push_back(str);
        }

        if (N > 32) {
            cout << 0 << '\n';
            continue;
        }

        int dist = INT_MAX;

        for (int j = 0; j < N - 2; j++) {
            for (int k = j + 1; k < N - 1; k++) {
                for (int l = k + 1; l < N; l++) {
                    int temp = getDist(v[j], v[k]) + getDist(v[j], v[l]) + getDist(v[k], v[l]);
                    dist = min(dist, temp);
                }
            }
        }
        
        cout << dist << '\n';
    }

    return 0;
}