#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> ans;
vector<bool> visited(10, false);

void back(int n) {
    if ((int)ans.size() == M) {
        for (const auto & a : ans)
            cout << a << " ";
        cout << "\n";

        return;
    }

    for (int i = n; i <= N; i++) {
        if (!visited[i]) {
            ans.push_back(i);   visited[i] = true;
            back(i + 1);
            ans.pop_back();     visited[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    back(1);

    return 0;
}