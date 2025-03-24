#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> ans;

void back(int num) {
    if ((int)ans.size() == M) {

        for (const auto & a : ans) {
            cout << a << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = num; i <= N; i++) {
        ans.push_back(i);
        back(i);
        ans.pop_back();
    }

}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    back(1);

    return EXIT_SUCCESS;
}

/*
vector<bool> visited(10, false);

void back_legacy(int num) {
    if ((int)ans.size() == M) {

        for (const auto & a : ans) {
            cout << a << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = num; i <= N; i++) {
        if (!visited[i] || (i == num)) {
            ans.push_back(i);   visited[i] = true;
            back_legacy(i);
            ans.pop_back();   visited[i] = false;
        }
    }

    visited[num] = true;
}
*/