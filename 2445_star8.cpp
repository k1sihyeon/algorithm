#include <iostream>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < N - i; j++)
            cout << "*";

        for (int j = 0; j < 2 * i; j++)
            cout << " ";

        for (int j = 0; j < N - i; j++)
            cout << "*";

        cout << "\n";
    }

    for (int i = 1; i < N; i++) {
        for (int j = N; j > i; j--)
            cout << "*";
        
        for (int j = 0; j < 2 * i; j++)
            cout << " ";

        for (int j = N; j > i; j--)
            cout << "*";

        cout << "\n";
    }

    return EXIT_SUCCESS;
}