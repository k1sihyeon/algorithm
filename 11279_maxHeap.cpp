#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> pq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;

        if (input == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
                continue;
            }

            cout << pq.top() << "\n";
            pq.pop();
            continue;
        }

        pq.push(input);
    }

    return 0;
}