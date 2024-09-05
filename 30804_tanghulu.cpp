#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, types = 0;
    int result = 0;
    int cnt[10];

    queue<int> tanghulu;

    memset(cnt, 0, sizeof(cnt));

    cin >> N;

    for (int i = 0; i < N; i++) {
        int fruit;
        cin >> fruit;
        tanghulu.push(fruit);

        if (cnt[fruit] == 0)
            types += 1;

        cnt[fruit] += 1;

        while (types > 2) {
            int front = tanghulu.front();
            cnt[front] -= 1;
            tanghulu.pop();

            if (cnt[front] == 0)
                types -= 1;
        }

        result = max(result, (int)tanghulu.size());
    }

    cout << result << endl;

    return 0;
}