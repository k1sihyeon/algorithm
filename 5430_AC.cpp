#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int T;
vector<char> cmdv;
//vector<string> arrv;
deque<string> deqs;

void printArr(deque<string> v) {
    cout << "[";

    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];

        if (i != (int)v.size()-1)
            cout << ",";
    }

    cout << "]\n";
}

void print(vector<int> v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string cmd;
    string arr;
    int n;
    bool dir;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cmdv.clear();
        deqs.clear();

        cmd.clear();
        arr.clear();
        n = 0;
        dir = true;

        cin >> cmd >> n >> arr;
//        cout << cmd << " " << n << " " << arr << "\n";
        //cout << "input done \n";

        for (int i = 0; i < (int)cmd.size(); i++) {
            if (cmd[i] != '\0')
                cmdv.push_back(cmd[i]);
        }

        string tmp = "";

        for (int i = 0; i < (int)arr.size(); i++) {

            if (arr[i] == '[')
                continue;
            
            else if ((arr[i] >= '0') && (arr[i] <= '9'))
                tmp.push_back(arr[i]);

            else if ((arr[i] == ',') || (arr[i] == ']')) {
                if (!tmp.empty()) {
                    deqs.push_back(tmp);
                    tmp.clear();
                }
            }                
        }

        for (int i = 0; i < (int)cmdv.size(); i++) {
            if (cmd[i] == 'R') {
                dir = !dir;

                //      ?
                // if (n == 1 && i == 0) {
                //     printArr(arrv);
                //     goto nextTestCase;
                // } 
            }

            else if (cmd[i] == 'D') {
                if (deqs.empty() || n == 0) {
                    cout << "error" << '\n';
                    goto nextTestCase;
                }
                else {
                    if (dir)
                        deqs.pop_front();
                    else
                        deqs.pop_back();
                } 
            }
        }

        if (!dir)
            reverse(deqs.begin(), deqs.end());

        printArr(deqs);

        nextTestCase:;
    }

    return 0;
}