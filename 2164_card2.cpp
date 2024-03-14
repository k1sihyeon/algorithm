#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    for (int i = 0; i < N; i++) {

        if (q.size() == 1) {
            cout << q.front() << '\n';
            break;
        }

        q.pop();

        q.push(q.front());
        q.pop();
    }

    return 0;
}