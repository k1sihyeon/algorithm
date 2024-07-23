#include <bits/stdc++.h>

using namespace std;

char toChar(int num) {
    return (char)((num % 26) + 65);
}

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if ((j % 2) == 0) { //odd col
                cout << toChar(i + n*j) << " ";
            }

            else if ((j % 2) == 1) { //even col
                cout << toChar(n - i - 1 + n*j) << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}