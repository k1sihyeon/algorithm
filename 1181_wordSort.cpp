#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cmp(string a, string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    else {
        return a.length() < b.length();
    }
}

int main(void) {
    int N;
    cin >> N;

    vector<string> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << v[i] << "\n";
        }
        else {
            if (v[i] != v[i - 1]) {
                cout << v[i] << "\n";
            }
        }
    }

    return 0;
}