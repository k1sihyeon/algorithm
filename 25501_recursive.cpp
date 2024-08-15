#include <iostream>

using namespace std;

int funcCall = 0;

int recursion(string& s, int l, int r) {
    funcCall += 1;

    if (l >= r)
        return 1;
    
    else if (s[l] != s[r])
        return 0;
    
    else
        return recursion(s, l+1, r-1);
}

int isPalindrome(string& s) {
    return recursion(s, 0, s.length() - 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        funcCall = 0;

        string s;
        cin >> s;

        cout << isPalindrome(s) << " " << funcCall << "\n";
    }

    return 0;
}