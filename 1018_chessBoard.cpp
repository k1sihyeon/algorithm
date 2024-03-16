#include <iostream>
#include <climits>

using namespace std;

int N, M;
string board[50];

string wb[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string bw[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int cmpWB(int x, int y) {
    int cnt = 0;

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (board[i][j] != wb[i - x][j - y]) 
                cnt++;
        }
    }
    
    return cnt;
}

int cmpBW(int x, int y) {
    int cnt = 0;

    for (int i = x; i < x + 8; i++) {
        for (int j = y; j < y + 8; j++) {
            if (board[i][j] != bw[i - x][j - y]) 
                cnt++;
        }
    }
    
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];

    int result = INT_MAX;

    for (int i = 0; i + 7 < N; i++) {
        for (int j = 0; j + 7 < M; j++) {
            int tmp = min(cmpWB(i, j), cmpBW(i, j));
            result = min(result, tmp);
        }
    }

    cout << result << "\n";

    return 0;
}