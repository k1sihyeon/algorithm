#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    if (n <= 0 || n > 100 || n % 2 == 0) {
        cout << "INPUT ERROR!" << "\n";
        return 0;
    }

    // top
    for (int i = 0; i < (n+1)/ 2; i++) {
        for (int j = 0; j < (n+1) / 2; j++) {
            if (j - i < 0)
                cout << " ";
            else
                cout << "*";
        }

        cout << "\n";
    }

    // bottom
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++)
            cout << " ";
        
        for (int j = 0; j < i + 2; j++)
            cout << "*";

        cout << "\n";
    }

    return 0;
}