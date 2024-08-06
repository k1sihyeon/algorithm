#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        map<string, int> closet;

        int num;
        cin >> num;

        for (int i = 0; i < num; i++) {
            string a, b;
            cin >> a >> b;

            closet[b] += 1;
        }

        int ans = 1;

        for (auto iter = closet.begin(); iter != closet.end(); iter++) {
            ans = ans * (iter->second + 1);
        }

        ans -= 1;

        cout << ans << endl;
    }

    return 0;
}