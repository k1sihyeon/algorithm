#include <iostream>

using namespace std;

int N, M, B;
int map[500][500];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;

    int num, max = 0, min = 256;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;
            map[i][j] = num;

            if (num > max) max = num;
            if (num < min) min = num;
        }
    }

    int minTime = 2147483647, minHeight = 0;
    for (int i = min; i <= max; i++) {
        int time = 0, block = B;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (map[j][k] > i) {
                    time += 2 * (map[j][k] - i);
                    block += map[j][k] - i;
                }
                else if (map[j][k] == i)
                    continue;
                else {
                    time += i - map[j][k];
                    block -= i - map[j][k];
                }
            }
        }

        if (block < 0)
            continue;

        if (time <= minTime) {
            minTime = time;
            minHeight = i;
        }
    }

    cout << minTime << ' ' << minHeight << '\n';

    return 0;
}