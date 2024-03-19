#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T;
vector<char> cmdv;
vector<int> arrv;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        string cmd;
        cin >> cmd;

        for (int i = 0; i < cmd.size(); i++) {
            cmdv.push_back(cmd[i]);
        }

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '[' || arr[i] == ']' || arr[i] == ',')
                continue;
            
            else
                arrv.push_back(arr[i] - '0');
        }

        for (int i = 0; i < cmdv.size(); i++) {
            
            if (cmd[i] == 'R') {
                reverse(arrv.begin(), arrv.end());
            }

            else if (cmd[i] == 'D') {
                if (arrv.empty()) {
                    cout << "error" << '\n';
                    break;
                }
                else
                    arrv.erase(arrv.begin());
            }
        }

    }

    return 0;
}