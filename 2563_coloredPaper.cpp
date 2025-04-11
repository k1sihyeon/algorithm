#include <iostream>
#include <vector>

using namespace std;

const int MAX   = 101;
const int SIZE  = 10;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<bool>> paper(MAX, vector<bool>(MAX, false));
    int result = 0;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;

        for (int x = X; x < X + SIZE; x++) {
            for (int y = Y; y < Y + SIZE; y++) {
                paper[x][y] = true;
            }
        }
    }

    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            if (paper[i][j])
                result += 1;
        }
    }

    cout << result << "\n";

    return EXIT_SUCCESS;
}