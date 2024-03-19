#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int M;
set<int> s;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;

    for (int i = 0; i < M; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int num;
            cin >> num;

            if (s.find(num) == s.end())
                s.insert(num);
        }

        else if (cmd == "remove") {
            int num;
            cin >> num;

            if (s.find(num) != s.end())
                s.erase(num);
        }

        else if (cmd == "check") {
            int num;
            cin >> num;

            if (s.find(num) != s.end())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }

        else if (cmd == "toggle") {
            int num;
            cin >> num;

            if (s.find(num) != s.end())
                s.erase(num);
            else
                s.insert(num);
        }

        else if (cmd == "all") {
            for (int i = 1; i <= 20; i++)
                s.insert(i);
        }

        else if (cmd == "empty") {
            s.clear();
        }

        else {

        }

    }

    return 0;
}