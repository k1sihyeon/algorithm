#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<string> result;
stack<int> s;

int n;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int num = 1;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        if (!s.empty() && s.top() == input) {
            s.pop();
            result.push_back("-");
        }
        else {
            while (num <= input) {
                s.push(num);
                result.push_back("+");
                num++;
            }

            if (s.top() == input) {
                s.pop();
                result.push_back("-");
            }
            else {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}