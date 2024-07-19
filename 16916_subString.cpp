#include <bits/stdc++.h>
using namespace std;

// KMP!

vector<int> failure(string s) {
    vector<int> f(s.size());

    int j = 0;

    for (int i = 1; i < s.size(); i++) {
        while ((j > 0) && (s[i] != s[j]))
            j = f[j - 1];

        if (s[i] == s[j]) {
            j += 1;
            f[i] = j;
        }
    }

    return f;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    vector<int> f = failure(b);
    int j = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        while ((j > 0) && (a[i] != b[j]))
            j = f[j - 1];

        if (a[i] == b[j])
            j += 1;

        if (j == b.size()) {
            cout << 1 << "\n";
            return;
        }
    }

    cout << 0 << "\n";

    return 0;
}