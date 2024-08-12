#include <bits/stdc++.h>
using namespace std;

stack<int> s;
vector<string> ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int seq = 1;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        // 입력된 수가 stack의 top이면 바로 뽑기
        if (!s.empty() && (s.top() == num)) {
            ans.push_back("-");
            s.pop();
        }
        else {
            // 입력된 수까지 push
            while (num >= seq) {
                ans.push_back("+");
                s.push(seq);
                seq += 1;
            }

            if (s.top() == num) {
                ans.push_back("-");
                s.pop();
            }
            else {
                // 입력된 수까지 push를 해도 top이 num이 아니다?
                // 오름차순 입력 규칙 위배
                cout << "NO" << "\n";
                return 0;
            }
        }
    }

    // output
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << "\n";

    return 0;
}