#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        stack<char> st;
        bool flag = true;
        string str;
        getline(cin, str);

        if (str == ".")
            break;
        
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] == '(' || str[i] == '[')
                st.push(str[i]);

            else if (str[i] == ')') {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else {
                    flag = false;
                    break;
                }
            }

            else if (str[i] == ']') {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag && st.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}