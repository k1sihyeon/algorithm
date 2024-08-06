#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
stack<pair<int, int>> s;
//index, value

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> ans(N, 0);

    //input
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back({i+1, num});
    }

    for (int i = 0; i < N; i++) {
        while (!s.empty() && (s.top().second < v[i].second)) {
            ans[s.top().first] = i + 1;
            s.pop();
        }

        s.push(v[i]);
    }
    
    //stack에 남은 값 뽑기
    while (!s.empty()) {
        ans[s.top().first] = 0;
        s.pop();
    }

    //print
    for(int i = 1; i <= (int)ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}