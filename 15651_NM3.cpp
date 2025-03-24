#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> ans;

void back() {
    if ((int)ans.size() == M) {
        for (const auto & a : ans) {
            cout << a << " ";
        }
        cout << "\n";
        
        return;
    }

    for (int i = 1; i <= N; i++) {
        ans.push_back(i);
        back();
        ans.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    back();

    return 0;
}