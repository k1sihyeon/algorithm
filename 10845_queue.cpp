#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N;
queue<int> q;

void Command(void) {
    string cmd;
    cin >> cmd;

    if (cmd == "push") {
        string num;
        cin >> num;

        q.push(stoi(num));
    }

    else if (cmd == "pop") {
        if (q.empty())
            cout << -1 << '\n';
        else {
            cout << q.front() << '\n';
            q.pop();
        }
    }

    else if (cmd == "size")
        cout << q.size() << '\n';

    else if (cmd == "empty")
        cout << q.empty() << '\n';

    else if (cmd == "front") {
        if (q.empty())
            cout << -1 << '\n';
        else
            cout << q.front() << '\n';
    }

    else if (cmd == "back") {
        if (q.empty())
            cout << -1 << '\n';
        else
            cout << q.back() << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        Command();
    }

    return 0;
}
