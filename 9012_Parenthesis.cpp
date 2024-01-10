#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    stack<char> stck;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int cnt = 0;
        bool flag = true;

        for (int j = 0; j < str.length(); j++) {
            
            if (str[j] == '(') {
                stck.push(str[j]);
                cnt++;
            }

            else if (str[j] == ')') {
                if (cnt <= 0) {
                    flag = false;
                    break;
                }
                else {
                    stck.pop();
                    cnt--;
                }
            }

        }

        if (flag && (cnt == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}