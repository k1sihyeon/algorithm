#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> board;
pair<int, int> heart;

pair<int, int> GetHeart() {
    for (int i = 2; i < N-1; i++) {
        for (int j = 2; j < N-1; j++) {
            if (board[i-1][j] == '*' && board[i][j-1] == '*' && board[i][j] == '*' && board[i][j+1] == '*' && board[i+1][j] == '*') {
                return {i, j};
            }       
        }
    }

    return {-1, -1};
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int leftArm = 0;
    int rightArm = 0;
    int waist = 0;
    int leftLeg = 0;
    int rightLeg = 0;
    pair<int, int> idx;

    cin >> N;
    board.assign(N + 1, vector<char>(N + 1, '_'));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char ch;
            cin >> ch;

            if (ch == '*') 
                board[i][j] = '*';
        }
    }

    // get heart idx
    heart = GetHeart();

    // get left arm
    idx = {heart.first, heart.second - 1};
    while ((idx.second >= 1) && (board[idx.first][idx.second] != '_')) {
        leftArm += 1;
        idx.second -= 1;
    }

    // get right arm
    idx = {heart.first, heart.second + 1};
    while ((idx.second <= N) && (board[idx.first][idx.second] != '_')) {
        rightArm += 1;
        idx.second += 1;
    }

    // get waist
    idx = {heart.first + 1, heart.second};
    while ((idx.first <= N) && (board[idx.first][idx.second] != '_')) {
        waist += 1;
        idx.first += 1;
    }

    // get left leg
    idx = {heart.first + waist + 1, heart.second - 1};
    while ((idx.first <= N) && (board[idx.first][idx.second] != '_')) {
        leftLeg += 1;
        idx.first += 1;
    }

    // get right leg
    idx = {heart.first + waist + 1, heart.second + 1};
    while ((idx.first <= N) && (board[idx.first][idx.second] != '_')) {
        rightLeg += 1;
        idx.first += 1;
    }

    cout << heart.first << " " << heart.second << "\n";
    cout << leftArm << " " << rightArm << " " << waist << " " << leftLeg << " " << rightLeg << "\n";

    return EXIT_SUCCESS;
}