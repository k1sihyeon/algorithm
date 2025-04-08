#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    stack<char> st;

    cin >> input;

    for (const auto & i : input) {
        if ((i >= 'A') && (i <= 'Z')) {
            cout << i;
            continue;
        }

        if (i == '(') {
            st.push(i);
        }
        else if (i == ')') {
            while (!st.empty() && (st.top() != '(')) {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if ((i == '*') || (i == '/')) {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(i);
        }
        else if ((i == '+') || (i == '-')) {
            while (!st.empty() && (st.top() != '(')) {
                cout << st.top();
                st.pop();
            }
            st.push(i);
        }
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return EXIT_SUCCESS;
}