#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = N-1; j > i; j--)
            cout << " ";
        
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";

        cout << "\n";
    }

    return EXIT_SUCCESS;
}