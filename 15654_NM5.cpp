#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> numbers;
vector<int> ans;
vector<bool> visited(10, false);

void back() {
    if ((int)ans.size() == M) {
        for (const auto & a : ans) {
            cout << a << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            ans.push_back(numbers[i]);  visited[i] = true;
            back();
            ans.pop_back();             visited[i] = false;
        }
    }
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());
    
    back();

    return EXIT_SUCCESS;
}