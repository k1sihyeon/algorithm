#include <iostream>

using namespace std;

int N;
int blue = 0;
int white = 0;
int paper[128][128];

bool IsSameColor(int x, int y, int size) {
    int color = paper[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (color != paper[i][j])
                return false;
        }
    }

    return true;
}

void ColorPaper(int x, int y, int size) {
    if (IsSameColor(x, y, size)) {
        if (paper[x][y] == 1)
            blue++;
        else
            white++;
    }
    else {
        int nSize = size / 2;
        ColorPaper(x, y, nSize);
        ColorPaper(x, y + nSize, nSize);
        ColorPaper(x + nSize, y, nSize);
        ColorPaper(x + nSize, y + nSize, nSize);
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int color;
            cin >> color;
            paper[i][j] = color;
        }
    }

    ColorPaper(0, 0, N);

    cout << white << '\n';
    cout << blue << '\n';

    return 0;
}