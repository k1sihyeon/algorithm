#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define endl '\n'

int N;
stack<int> s;

void Command(void) {
    int num;
    string cmd;
    cin >> cmd;

    if (cmd == "push") {
        cin >> num;
        s.push(num);
    }

    else if (cmd == "pop") {
        if (s.empty())
            cout << -1 << endl;
        else {
            cout << s.top() << endl;
            s.pop();
        }
    }

    else if (cmd == "size") {
        cout << s.size() << endl;
    }

    else if (cmd == "empty") {
        if (s.empty())
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    else if (cmd == "top") {
        if (s.empty())
            cout << -1 << endl;
        else
            cout << s.top() << endl;
    }

    else {
        cout << "Invalid command" << endl;
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