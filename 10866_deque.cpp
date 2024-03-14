#include <iostream>
#include <deque>

using namespace std;

#define endl '\n'

deque<int> dq;

void Command(void) {
    string cmd;
    cin >> cmd;

    if (cmd == "push_front") {
        int num;
        cin >> num;
        dq.push_front(num);
    }

    else if (cmd == "push_back") {
        int num;
        cin >> num;
        dq.push_back(num);
    }

    else if (cmd == "pop_front") {
        if (dq.empty()) 
            cout << -1 << endl;
        else {
            cout << dq.front() << endl;
            dq.pop_front();
        }
    }

    else if (cmd == "pop_back") {
        if (dq.empty()) 
            cout << -1 << endl;
        else {
            cout << dq.back() << endl;
            dq.pop_back();
        }
    }

    else if (cmd == "size") {
        cout << dq.size() << endl;
    }

    else if (cmd == "empty") {
        cout << dq.empty() << endl;
    }

    else if (cmd == "front") {
        if (dq.empty()) 
            cout << -1 << endl;
        else 
            cout << dq.front() << endl;
    }

    else if (cmd == "back") {
        if (dq.empty()) 
            cout << -1 << endl;
        else 
            cout << dq.back() << endl;
    }

    else {
        cout << "Invalid Command" << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        Command();
    }

    return 0;
}