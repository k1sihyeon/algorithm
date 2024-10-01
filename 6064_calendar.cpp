#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, result = -1;

    cin >> T;

    for (int i = 0; i < T; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        while (true) {
            if (x == y) {
                result = x;
                break;
            }

            else if (x > M * N) {
                result = -1;
                break;
            }

            if (x < y)
                x += M;
            
            else
                y += N;
        }

        cout << result << "\n";
    }

    return 0;
}