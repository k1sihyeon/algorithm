#include <iostream>

using namespace std;

bool isBlank(int i, int j) {
    if ((i == 0) || (j == 0))
        return false;

    if (((i % 3) == 1) && ((j % 3) == 1))
        return true;

    return isBlank(i / 3, j / 3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (isBlank(i, j) ? ' ' : '*');

        cout << '\n';
    }

    return 0;
}
