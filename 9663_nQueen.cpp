#include <iostream>
#include <cmath>

using namespace std;

int N;
int result = 0;

int board[15];

bool isPlacable(int idx) {
    for (int i = 0; i < idx; i++) {
        if ((board[idx] == board[i]) || (abs(board[idx] - board[i]) == idx - i))
            return false;
    }

    return true;
}

void back(int idx) {
    if (idx == N) {
        result += 1;
        return;
    }
    else {
        for (int i = 0; i < N; i++) {
            board[idx] = i;     // board[idx][i]에 queen

            if (isPlacable(idx))
                back(idx + 1);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    back(0);

    cout << result << "\n";

    return 0;
}