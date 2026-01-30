#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> buff;

void drawStar(int x, int y, int size) {
    if ((size == 1)) {
        buff[y][x] = '*';
        
        if ((y % 3) == 1) {
            buff[y + 1][x - 1] = '*';
            buff[y + 1][x] = '*';
            buff[y + 1][x + 1] = '*';
        }

        return;
    }

    int newSize = size / 2;

    drawStar(x, y, newSize); // Top
    drawStar(x - newSize, y + newSize, newSize); // Bottom left
    drawStar(x + newSize, y + newSize, newSize); // Bottom right
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    buff.assign(N, vector<char>(2 * N - 1, ' '));
    
    drawStar(N - 1, 0, N);

    for (const auto& row: buff) {
        for (const auto& ch : row)
            cout << ch;
        cout << '\n';
    }

    return 0;
}
