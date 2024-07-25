#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
stack<int> s;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        while (!s.empty() && (s.top() <= v[i]))
            s.pop();
        
        ans += s.size();
        s.push(v[i]);
    }

    cout << ans << "\n";

    return 0;
}
