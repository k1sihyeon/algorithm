#include <bits/stdc++.h>
using namespace std;

map<string, string> password;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string a, b;
        cin >> a >> b;
        password.insert({a, b});
    }

    for (int i = 0; i < M; i++) {
        string a;
        cin >> a;

        cout << password[a] << "\n";
    }

    return 0;
}